#include "listenthread.h"
/*
public:
    ListenThread getListenThread();
public slots:
    void closeListen();
signals:
    incomingConnection;
    stopListen;
private:
    ListenThread lt;
    QTcpServer server;
    QTcpSocket serverSocket;
    ListenThread();*/

ListenThread ListenThread::getListenThread()
{
    if(lt==null)
    {
        lt = new ListenThread(21);
    }
    return lt;
}

ListenThread::ListenThread(int port)
{
    server = new QTcpServer(QHostAddress::Any, port);
    serverSocket = new QTcpSocket();
    serverSocket.setSocketDescriptor(++socketDescriptor)
}
