#include "transferqueueitem.h"

TransferQueueItem::TransferQueueItem(QObject *parent) :
    QObject(parent)
{
}
TransferQueueItem::TransferQueueItem(bool download, QString localDir, QString ftpDir, QString fileName, bool append, qint64 sizeStart) :
    QObject(0)
{
    m_download=download;
    m_localDir = localDir;
    m_ftpDir = ftpDir;
    m_fileName= fileName;
    m_append=append;
    m_sizeStart=sizeStart;
}
TransferQueueItem::TransferQueueItem(bool download, QString localDir, QString ftpDir, QString fileName, bool append, qint64 sizeStart, QObject * parent) :
    QObject(parent)
{
    m_download=download;
    m_localDir = localDir;
    m_ftpDir = ftpDir;
    m_fileName= fileName;
    m_append=append;
    m_sizeStart=sizeStart;
}
bool TransferQueueItem::isDownload() {
    return m_download;
}
QString TransferQueueItem::getLocalDir() {
    return m_localDir;
}
QString TransferQueueItem::getFtpDir(){
    return m_ftpDir;
}
QString TransferQueueItem::getFileName(){
    return m_fileName;
}
bool TransferQueueItem::shouldResume(){
    return m_append;
}
qint64 TransferQueueItem::bytesComplete(){
    return m_sizeStart;
}
void TransferQueueItem::addChild(QObject * child){
    killUponDeath.append(child);

}
TransferQueueItem::~TransferQueueItem(){
    while (!killUponDeath.isEmpty()) {
         delete killUponDeath.takeFirst();
    }
}

