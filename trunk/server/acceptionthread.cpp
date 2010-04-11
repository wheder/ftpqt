#include "acceptionthread.h"
/*
    .AcceptionThread single = null;
    .ReqQueue requeuestsQueue;
    .AcceptionThread(ReqQueue reqQueue);
    .bool decideConnect();
    QueueItem createNewRequest();
    void enqueueRequest(QueueItem accepted);
    void sendFullCapacity();*/
AcceptionThread single = null;

void AcceptionThread::getAcceptionThread()
{
    if(single==null)
    {
        single = new AcceptionThread();
    }
    return single;
}


AcceptionThread::AcceptionThread()
{
    requestsQueue = ReqQueue.getReqQueue();
}

bool AcceptionThread::decideConnect()
{
    return !requestsQueue.isFull();
}

QueueItem AcceptionThread::createNewRequest()
{
    if(AcceptionThread::decideConnect())
    {

    }
}
