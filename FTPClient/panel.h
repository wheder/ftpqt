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
    void setFTPConn(QFtp **ftp);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::Panel *ui;
    QHash<QString, bool> isDirLocal;
    QString currentPathLocal;
    QHash<QString, bool> isDirFTP;
    QString currentPathFTP;
    QFtp **ftp_con;
    bool localPanelActive;





private slots:
    void on_renameButton_clicked();
    void on_cdUpFTP_clicked();
    void on_treeWidgetFTP_itemActivated(QTreeWidgetItem* item, int column);
    void on_treeWidgetLocal_itemActivated(QTreeWidgetItem* item, int column);
};

#endif // PANEL_H
