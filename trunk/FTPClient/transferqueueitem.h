#ifndef TRANSFERQUEUEITEM_H
#define TRANSFERQUEUEITEM_H

#include <QObject>
#include <QList>

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
    bool shouldResume();
    qint64 bytesComplete();
    void addChild(QObject * child);
signals:

public slots:


private:
    bool m_download;
    QString m_localDir;
    QString m_ftpDir;
    QString m_fileName;
    bool m_append;
    qint64 m_sizeStart;
    QList<QObject *> killUponDeath;
};

#endif // TRANSFERQUEUEITEM_H