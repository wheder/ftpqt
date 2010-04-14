#ifndef TRANSFERQUEUEITEM_H
#define TRANSFERQUEUEITEM_H

#include <QObject>
#include <QList>
#include "qxftp.h"
#include <QProgressBar>

class TransferQueueItem : public QObject
{
Q_OBJECT
public:
    explicit TransferQueueItem(QObject *parent = 0);
    TransferQueueItem(bool download, QString localDir, QString ftpDir, QString fileName, bool append, qint64 sizeStart, QObject * parent);
    TransferQueueItem(bool download, QString localDir, QString ftpDir, QString fileName, bool append, qint64 sizeStart );
    ~TransferQueueItem();

    bool isDownload();
    QString getLocalDir();
    QString getFtpDir();
    QString getFileName();
    QProgressBar * getProgressBar();
    bool shouldResume();
    qint64 bytesComplete();
    void addChild(QObject * child);
    void addProgress(QProgressBar * child);
    void setId(int id);
    int getId();
    void connectFtp(QxFtp * conn);
    QxFtp * conn();
signals:

private slots:
    void setComplete(int amoutn);
    void updateProgress(QxFtp *, qint64 current, qint64 total);

private:
    int id;
    bool m_download;
    QString m_localDir;
    QString m_ftpDir;
    QString m_fileName;
    bool m_append;
    qint64 m_sizeStart;
    QProgressBar *  m_progress;
    QList<QObject *> killUponDeath;

    QxFtp * m_conn;

};

#endif // TRANSFERQUEUEITEM_H
