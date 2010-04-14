#ifndef UPLOADTHREAD_H
#define UPLOADTHREAD_H

#include <QThread>
#include <QFtp>
#include <QQueue>
#include <QFile>
#include <QString>
#include <QIODevice>
#include "transferqueueitem.h"



class UploadThread : public QThread

{
Q_OBJECT

public:

    void setConnection(QFtp * connection);
    void setTransferItem(TransferQueueItem * item);

    void upload();
    void run();
private:
    QFtp * conn;
    TransferQueueItem * itemToTransfer;
signals:
    void newPendingItem(TransferQueueItem * item);
};

#endif // UPLOADTHREAD_H
