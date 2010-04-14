#include "uploadthread.h"
#include "transferqueueitem.h"


void UploadThread::run()
{
    this->upload();
    this->exec();
}

void UploadThread::setConnection(QFtp * connection)
{
    this->conn = connection;
}

void UploadThread::setTransferItem(TransferQueueItem * item)
{
    this->itemToTransfer = item;
}

void UploadThread::upload()
{
    QFile * file = new QFile(itemToTransfer->getLocalDir()+QString("/")+itemToTransfer->getFileName());
    if (!file->open(QIODevice::ReadOnly)) {
        //????????????
        //QMessageBox::critical(this, tr("Error"), tr("Cannot open file '%1' for reading!").arg(itemToTransfer->getFileName()));
        return;
    }

    itemToTransfer->setId(conn->put(file, itemToTransfer->getFtpDir()+QString("/")+itemToTransfer->getFileName()));
    emit newPendingItem(itemToTransfer);
}

