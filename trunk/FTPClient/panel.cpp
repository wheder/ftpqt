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
    //item->setText(0, urlInfo.name()+(urlInfo.isDir() ? "/" : ""));
    item->setText(0, urlInfo.name());
    item->setText(1, QString::number(urlInfo.size()));
    item->setText(2, urlInfo.lastModified().toString());

    // QPixmap pixmap(urlInfo.isDir() ? "./images/dir.png" : "./images/file.png");

    //item->setIcon(0, pixmap);

    //std::cout << QString::number(pixmap.size().rwidth()).toStdString() << std::endl;

    //isDirectory[urlInfo.name()] = urlInfo.isDir();

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
    //    QString fileName;
    //if (fileName.isEmpty())
    //        fileName = "*";
    files = currentDir.entryList(QStringList(QString("*")));

    for (int i = 0; i < files.size(); ++i) {
        QFile file(currentDir.absoluteFilePath(files[i]));

        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText(0, QFileInfo(file).fileName());
        item->setText(1, QString::number(QFileInfo(file).size()));
        item->setText(2, QFileInfo(file).created().toString());



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
        std::cout << ftp_con << std::endl;

        (*ftp_con)->cd(name);
        (*ftp_con)->list();


    }
}


void Panel::setFTPConn(QFtp **ftp)
{   
    ftp_con = ftp;

}
