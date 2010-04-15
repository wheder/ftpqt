#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>
#include <QtNetwork>
#include "panel.h"
#include "qxftp.h"
#include <QQueue>
#include "transferqueueitem.h"

namespace Ui {
    class Connection;
}

class Connection : public QDialog {
    Q_OBJECT
    struct Command {
        int id;
        TransferQueueItem * itemToTransfer;
    };
public:
    Connection(QWidget *parent = 0);
    ~Connection();
    QxFtp *ftp_conn;
    void pwd();
protected:
    void changeEvent(QEvent *e);
    void ftp_connect();
    void ftp_disconnect();

private:
    Ui::Connection *ui;

    Panel *panel;
    QString currentPathFTP;
    QQueue<TransferQueueItem *> transferQueue;
    QQueue<TransferQueueItem *> pendingQueue;
    void startTransfer(QxFtp * conn ,TransferQueueItem * itemToTransfer);
    QList<QxFtp *> all_connections;
    int max_connections;

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
    void ftpCommandStarted(QxFtp *, int id);
    void ftpCommandFinished(QxFtp *, int, bool error);
    void addToList(QxFtp *, const QUrlInfo &urlInfo);
    void ftp_rawCommandReply( QxFtp *, int code, const QString &text );
    void anonymousChanged(int newState);
    void addItemToTransferQueue(TransferQueueItem * item);
    void queueChecked(QxFtp * connection);
    void queueCheckedFirst(QxFtp * connection);
    void setupTransfers();

signals:
    void pwdChanged(const QString &);
    void canTransfer(QxFtp*);
};

#endif // CONNECTION_H
