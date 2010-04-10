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


void Panel::setFTPConn(QFtp **ftp)
{   
    ftp_con = ftp;

}


void Panel::on_cdUpFTP_clicked()
{
    ui->treeWidgetFTP->clear();
    isDirFTP.clear();
    currentPathFTP = currentPathFTP.left(currentPathFTP.lastIndexOf('/'));
    if (currentPathFTP.isEmpty()) {
        ui->cdUpFTP->setEnabled(false);
        (*ftp_con)->cd("/");
    } else {
        (*ftp_con)->cd(currentPathFTP);
    }
    (*ftp_con)->list();

}

void Panel::on_renameButton_clicked()
{
    std::cout <<  ui->treeWidgetFTP->isActiveWindow() << std::endl;
    std::cout <<  ui->treeWidgetLocal->isActiveWindow() << std::endl;
    //ui->treeWidgetFTP->

}
