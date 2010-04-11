#ifndef ACCEPTIONTHREAD_H
#define ACCEPTIONTHREAD_H

#include <QThread>
#include <QFtp>
#include <QNetworkAccessManager>
#include "queueitem.h"
#include "reqqueue.h"

class AcceptionThread : public QThread
{
    Q_OBJECT

public:
    void getAcceptionThread();

public slots:

signals:

private:
    AcceptionThread single;
    ReqQueue requeuestsQueue;

    AcceptionThread();
    bool decideConnect();
    QueueItem createNewRequest();
    void enqueueRequest(QueueItem accepted);
    void sendFullCapacity();
    void sendAccepted();
};

#endif // ACCEPTIONTHREAD_H
