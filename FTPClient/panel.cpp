#include "panel.h"
#include "ui_panel.h"


Panel::Panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel)
{
    currentPathLocal = QString(".");
    ui->setupUi(this);
    addItemLocal();
    ftp_con = NULL;
    localPanelActive = false;
}

Panel::~Panel()
{
    delete ui;
}

void Panel::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Panel::addItemFTP(const QUrlInfo &urlInfo)
{
    QTreeWidgetItem *item = new QTreeWidgetItem;

    item->setText(0, urlInfo.name());
    item->setText(1, QString::number(urlInfo.size()));
    item->setText(2, urlInfo.lastModified().toString());

    QPixmap pixmap(urlInfo.isDir() ? ":/images/dir.png" : ":/images/file.png");

    QIcon icon(pixmap);
    item->setIcon(0, icon);    

    ui->treeWidgetFTP->addTopLevelItem(item);
    if (!ui->treeWidgetFTP->currentItem()) {
        ui->treeWidgetFTP->setCurrentItem(ui->treeWidgetFTP->topLevelItem(0));
    }
    isDirFTP[urlInfo.name()] = urlInfo.isDir();
}

void Panel::addItemLocal()
{
    QDir currentDir = QDir(currentPathLocal);
    QStringList files;

    ui->localPathLineEdit->setText(currentPathLocal);

    files = currentDir.entryList(QStringList(QString("*")));

    for (int i = 0; i < files.size(); ++i) {
        QFile file(currentDir.absoluteFilePath(files[i]));

        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, QFileInfo(file).fileName());
        item->setText(1, QString::number(QFileInfo(file).size()));
        item->setText(2, QFileInfo(file).created().toString());
        QPixmap pixmap(QFileInfo(file).isDir() ? ":/images/dir.png" : ":/images/file.png");

        QIcon icon(pixmap);
        item->setIcon(0, icon);


        ui->treeWidgetLocal->addTopLevelItem(item);
        isDirLocal[QFileInfo(file).fileName()] = QFileInfo(file).isDir();
    }

}

void Panel::on_treeWidgetLocal_itemActivated(QTreeWidgetItem* item, int /*column*/)
{
    QString name = item->text(0);
    if (isDirLocal.value(name)) {
        ui->treeWidgetLocal->clear();
        isDirLocal.clear();
        currentPathLocal += '/';
        currentPathLocal += name;
        QDir actual = QDir(currentPathLocal);
        currentPathLocal = actual.absolutePath();
        addItemLocal();
    }
}

void Panel::on_treeWidgetFTP_itemActivated(QTreeWidgetItem* item, int /*column*/)
{
    QString name = item->text(0);
    if (isDirFTP.value(name)) {
        ui->treeWidgetFTP->clear();
        isDirFTP.clear();
        currentPathFTP += '/';
        currentPathFTP += name;

        ui->cdUpFTP->setEnabled(true);
        (*ftp_con)->cd(name);
        (*ftp_con)->list();

    }
}


void Panel::setFTPConn(QxFtp **ftp)
{   
    ftp_con = ftp;


}

void Panel::on_cdUpFTP_clicked()
{
    ui->treeWidgetFTP->clear();
    isDirFTP.clear();
    //currentPathFTP = currentPathFTP.left(currentPathFTP.lastIndexOf('/'));
    (*ftp_con)->cd("..");
    /*
    if (currentPathFTP.isEmpty()) {
        ui->cdUpFTP->setEnabled(false);
        (*ftp_con)->cd("/");
    } else {
        (*ftp_con)->cd(currentPathFTP);
    }
    */
    (*ftp_con)->list();
    if (ui->ftpPathLineEdit->text() == "/") ui->cdUpFTP->setEnabled(false);

}

void Panel::on_cdUpLocal_clicked()
{
    ui->treeWidgetLocal->clear();
    isDirLocal.clear();
    //currentPathLocal = currentPathLocal.left(currentPathLocal.lastIndexOf('/'));
    currentPathLocal = currentPathLocal + "/..";
    QDir actual = QDir(currentPathLocal);
    currentPathLocal = actual.absolutePath();
    addItemLocal();
}

void Panel::on_renameButton_clicked()
{

    if (!ui->treeWidgetFTP->currentItem()) {//kdyz tam neni ani jedna polozka
        QMessageBox::information(this, tr("Info"), tr("No item available!"));
        return;
    }
    bool ok;
    QString text = QInputDialog::getText(
            this,
            tr("Rename"),
            tr("Rename '<b>%1</b>'<br /> to ").arg(ui->treeWidgetFTP->currentItem()->text(0)),
            QLineEdit::Normal,
            ui->treeWidgetFTP->currentItem()->text(0),
            &ok
            );

    if (ok && !text.isEmpty()) {
        (*ftp_con)->rename(ui->treeWidgetFTP->currentItem()->text(0), text);
        ui->treeWidgetFTP->clear();
        (*ftp_con)->list();
    }   
}

void Panel::dirsOnFTPDeleted(QxFtp *,bool error)
{
    disconnect((*ftp_con), SIGNAL(x_done(QxFtp *,bool)), this, SLOT(dirsOnFTPDeleted(QxFtp *,bool)));
    ui->treeWidgetFTP->clear();
    isDirFTP.clear();
    (*ftp_con)->list();
}

void Panel::filesOnFTPDeleted(QxFtp *,bool error)
{
   disconnect((*ftp_con), SIGNAL(x_done(QxFtp *,bool)), this, SLOT(filesOnFTPDeleted(QxFtp *,bool)));
   deleteFile(currentPathFTP, rootDirToDelete, true);
   connect((*ftp_con), SIGNAL(x_done(QxFtp *,bool)), this, SLOT(dirsOnFTPDeleted(QxFtp *,bool)));
}

void Panel::on_deleteButton_clicked()
{
    if (!ui->treeWidgetFTP->currentItem())
    {
        QMessageBox::information(this, tr("Info"), tr("No item available!"));
        return;
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("FTPClient"),
                                  "Do you really want to delete file or directory: <br /><b>" + QString(ui->treeWidgetFTP->currentItem()->text(0)) + "</b> ?",
                                  QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if (reply == QMessageBox::Yes)
    {
        QString fileName = ui->treeWidgetFTP->currentItem()->text(0);
        if (fileName != QString(".") && fileName != (".."))
        {
            if (isDirFTP.value(fileName))
            {
                rootDirToDelete = QString(fileName);


                deleteFile(currentPathFTP, fileName, false);
                isDirFTP.clear();
                (*ftp_con)->list();
                connect((*ftp_con), SIGNAL(x_done(QxFtp *,bool)), this, SLOT(filesOnFTPDeleted(QxFtp *,bool)));
            }
            else
            {
                (*ftp_con)->remove(fileName);
                ui->treeWidgetFTP->clear();
                isDirFTP.clear();
                (*ftp_con)->list();
            }
        }
    }    
}

void Panel::directoryStructureOnFtpCreated(QxFtp *, bool /*error*/) {
    disconnect((*ftp_con), SIGNAL(x_done(QxFtp *, bool)), this, SLOT(directoryStructureOnFtpCreated(QxFtp *, bool)));
    ui->treeWidgetFTP->clear();
    ui->treeWidgetFTP->setDisabled(false);
    isDirFTP.clear();
    (*ftp_con)->list();
    ui->treeWidgetFTP->setDisabled(false);
    connect((*ftp_con), SIGNAL(x_done(QxFtp*, bool)), this, SLOT(startTransfers(QxFtp *, bool)));
}

void Panel::on_uploadButton_clicked()
{
    if (!ui->treeWidgetLocal->currentItem())
    {
        QMessageBox::critical(this, tr("Error"), tr("No item available!"));
        return;
    }
    ui->treeWidgetFTP->setDisabled(true);

    QString fileName = ui->treeWidgetLocal->selectedItems().at(0)->text(0);  //->//currentItem()->text(0);
    if (isDirLocal.value(fileName)) {
        if (!isDirFTP.value(fileName)) {
            (*ftp_con)->mkdir(fileName);
        }
        uploadDir(currentPathLocal+"/"+fileName, ui->ftpPathLineEdit->text()+"/"+fileName, fileName);
    }
    else {
        uploadFile(currentPathLocal, ui->ftpPathLineEdit->text(), fileName);
    }
    //pokracovat se bude az se to plneni seznamu zklidni.
    connect((*ftp_con), SIGNAL(x_done(QxFtp *, bool)), this, SLOT(directoryStructureOnFtpCreated(QxFtp *, bool)));
    (*ftp_con)->cd(".");
}

void Panel::uploadDir(QString local, QString ftp, QString dirname) {
    QDir currentDir = QDir(local);
    QStringList files;

    files = currentDir.entryList(QStringList(QString("*")));

    (*ftp_con)->cd(dirname);
    isDirFTP.clear();
    ui->treeWidgetFTP->clear();
    (*ftp_con)->list();
    for (int i = 0; i < files.size(); ++i) {
        QFile file(currentDir.absoluteFilePath(files[i]));
        if(QFileInfo(file).isDir()) {
            if (QFileInfo(file).fileName() == "." || QFileInfo(file).fileName() == ".."){
                //ignorujeme, jinak se zacyklime
            }
            else {
                if (!isDirFTP.value(ftp+"/"+QFileInfo(file).fileName())) {
                    std::cout << "creating dir " <<ftp.toStdString()<<"/"<<QFileInfo(file).fileName().toStdString() << std::endl;
                    (*ftp_con)->mkdir(ftp+"/"+QFileInfo(file).fileName());
                }
                uploadDir(local+"/"+QFileInfo(file).fileName(), ftp+"/"+QFileInfo(file).fileName(), QFileInfo(file).fileName());
                isDirFTP.clear();
                ui->treeWidgetFTP->clear();
                (*ftp_con)->list();
            }
        }
        else {
            uploadFile(local, ftp, QFileInfo(file).fileName());
        }
    }

    (*ftp_con)->cd("..");
}
void Panel::uploadFile(QString local, QString ftp, QString file) {
    //std::cout << "moving from: " << local.toStdString() << " to: " << ftp.toStdString() << " file:" << file.toStdString() << std::endl;
    int fileSize = 0;
    TransferQueueItem * item;
    QHash<QString, bool>::const_iterator i = isDirFTP.find(file);
    if (i == isDirFTP.end()) {//file neexistuje ;-)
      item = new TransferQueueItem(false, local, ftp, file, false, 0, (*ftp_con));

    }
    else { //existuje, budeme appendovat :-/
        QTreeWidgetItem * t = ui->treeWidgetFTP->findItems(file, Qt::MatchExactly, 0).first();
        item = new TransferQueueItem(false, local, ftp, file, true, t->text(1).toInt(), (*ftp_con));
        fileSize = t->text(1).toInt();
    }
    //if (isDirFTP.find())

    QProgressBar * p = new QProgressBar(ui->scrollAreaWidgetContents);
    p->setMaximum(QFile(local+file).size());
    p->setValue(0);
    QLabel * l = new QLabel(ui->scrollAreaWidgetContents);
    l->setText(file);
    l->setToolTip(local+QString(" -> ")+ftp);
    QPushButton * t = new QPushButton(QString("Cancel"), ui->scrollAreaWidgetContents);

    int level = ui->scrollAreaWidgetContents->children().size()/3;
    ui->gridLayout_2->addWidget(l, level, 0, 1,1,0);
    item->addChild(l);
    ui->gridLayout_2->addWidget(p, level, 1, 1,1,0);
    item->addProgress(p);
    ui->gridLayout_2->addWidget(t, level, 2, 1,1,0);
    item->addChild(t);
    emit newTransferQueueItemCreated(item);

    //QMessageBox::information(this, tr("Info"), tr("%1").arg(time.toString(Qt::ISODate)));
    //ui->formLayout->setWidget(0, QFormLayout::LabelRole, l);
    //ui->formLayout->insertRow(0, l);
    //ui->gridLayout_2->insertRow(0, l->text(), p);

    //formLayout->setWidget(0, QFormLayout::LabelRole, label_3);
    //formLayout->setWidget(0, QFormLayout::FieldRole, progressBar);
    //p->
    //ui->transferScrollArea->addScrollBarWidget(p, Qt::AlignLeft);
    //if (!ui->treeWidgetLocal->isItemSelected()) QMessageBox::information(this, tr("No item selected!"));
    //if (!ui->treeWidgetLocal->currentItem())QMessageBox::information(this, tr("Info"), tr("No item selected!"));
    //QMessageBox::information(this, tr("Info"),  ui->treeWidgetLocal->currentItem()->text(0));

    std::cout << file.toStdString() << std::endl;
}

void Panel::deleteFile(QString ftp, QString fileName, bool delDirs)
{
    (*ftp_con)->cd(fileName);
    ftp = ftp + QString("/") + fileName;   
    QDir currentDir = QDir(ftp);
    QStringList files;
    files = currentDir.entryList(QStringList(QString("*")));
    for (int i = 0; i < files.size(); ++i) {
        QFile file(currentDir.absoluteFilePath(files[i]));
        if(QFileInfo(file).isDir()) {
            if (QFileInfo(file).fileName() == "." || QFileInfo(file).fileName() == ".."){
                //ignorujeme, jinak se zacyklime
            }
            else {
                deleteFile(ftp, QFileInfo(file).fileName(), delDirs);
            }
        }
        else {
            std::cout << "deleting file: " << currentPathFTP.toStdString() << "/" << QFileInfo(file).fileName().toStdString() << std::endl;
            (*ftp_con)->remove(QFileInfo(file).fileName());
        }
    }
    (*ftp_con)->cd("..");    
    if (delDirs)
    {
        (*ftp_con)->rmdir(fileName);
    }
}

void Panel::changePwd(const QString & pwd) {
    ui->ftpPathLineEdit->setText(pwd);
}
void Panel::startTransfers(QxFtp * , bool) {
    disconnect((*ftp_con), SIGNAL(x_done(QxFtp*, bool)), this, SLOT(startTransfers(QxFtp *, bool)));
    emit canTransfer((*ftp_con));
    //emit canTransferNow();
}

