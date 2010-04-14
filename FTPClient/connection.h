#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>
#include <QtNetwork>
#include "panel.h"
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
    QFtp *ftp_conn;
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
    QQueue<Command> doneQueue;
    void startTransfer(QFtp * conn ,TransferQueueItem * itemToTransfer);

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
    void ftpCommandStarted(int id);
    void ftpCommandFinished(int, bool error);
    void addToList(const QUrlInfo &urlInfo);
    void ftp_rawCommandReply( int code, const QString &text );
    void anonymousChanged(int newState);
    void addItemToTransferQueue(TransferQueueItem * item);
    void queueChecked(QFtp * connection);

signals:
    void pwdChanged(const QString &);
};

#endif // CONNECTION_H
