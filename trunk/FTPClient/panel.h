#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QtNetwork>
#include <QUrlInfo>
#include <QHash>
#include <QDir>
#include <iostream>
#include <cstdio>
#include <QPixmap>
#include <QTreeWidgetItem>
#include <QIcon>
#include <QMessageBox>
#include <QInputDialog>
#include <QProgressBar>
#include <QTime>
#include "transferqueueitem.h"
#include "qxftp.h"


namespace Ui {
    class Panel;
}

class Panel : public QWidget {
    Q_OBJECT
public:
    Panel(QWidget *parent = 0);
    ~Panel();
    void addItemFTP(const QUrlInfo &urlInfo);
    void addItemLocal();
    void setFTPConn(QxFtp **ftp);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::Panel *ui;
    QHash<QString, bool> isDirLocal;
    QString currentPathLocal, rootDirToDelete;
    QHash<QString, bool> isDirFTP;
    QString currentPathFTP;
    QxFtp **ftp_con;
    bool localPanelActive;
    void uploadDir(QString local, QString ftp, QString dirname);
    void uploadFile(QString local, QString ftp, QString file);
    void deleteFile(QString ftp, QString fileName, bool delDirs);
private slots:
    void on_uploadButton_clicked();
    void on_renameButton_clicked();
    void on_deleteButton_clicked();
    void on_cdUpFTP_clicked();
    void on_treeWidgetFTP_itemActivated(QTreeWidgetItem* item, int column);
    void on_treeWidgetLocal_itemActivated(QTreeWidgetItem* item, int column);
    void changePwd(const QString & pwd);
    void on_cdUpLocal_clicked();
    void directoryStructureOnFtpCreated(QxFtp *, bool error);
    void startTransfers(QxFtp *, bool a);
    void filesOnFTPDeleted(QxFtp *, bool error);
    void dirsOnFTPDeleted(QxFtp *,bool error);
signals:
    void canTransfer(QxFtp * conn);
    void canTransferNow();
    void newTransferQueueItemCreated(TransferQueueItem * i);
};

#endif // PANEL_H
