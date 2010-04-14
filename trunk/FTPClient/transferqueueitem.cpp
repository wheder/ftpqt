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
void TransferQueueItem::addProgress(QProgressBar * child){
    killUponDeath.append(child);
    m_progress = child;
    connect(m_progress, SIGNAL(valueChanged(int)), this, SLOT(setComplete(int)));

}
QProgressBar * TransferQueueItem::getProgressBar() {
    return m_progress;
}
TransferQueueItem::~TransferQueueItem(){
    while (!killUponDeath.isEmpty()) {
         delete killUponDeath.takeFirst();
    }
}

void TransferQueueItem::setComplete(int amoutn) {
    m_sizeStart=amoutn;
}

void TransferQueueItem::updateProgress(qint64 current, qint64 total) {
    m_progress->setValue(current);
    m_progress->setMaximum(total);
}

void TransferQueueItem::setId(int id)
{
    this->id = id;
}

int TransferQueueItem::getId()
{
    return id;
}
