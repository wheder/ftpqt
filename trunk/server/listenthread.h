#ifndef LISTENTHREAD_H
#define LISTENTHREAD_H

#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>

class ListenThread : public QThread
{
    Q_OBJECT
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
    unsigned int socketDesriptor = 0;
    ListenThread(unsigned int port);
};

#endif // LISTENTHREAD_H
