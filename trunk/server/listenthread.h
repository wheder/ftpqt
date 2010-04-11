#ifndef LISTENTHREAD_H
#define LISTENTHREAD_H

#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>

class ListenThread : public QThread
{
    Q_OBJECT
public:
    static ListenThread getListenThread();
public slots:
    void closeListen();
signals:
    void incomingConnection();
    void stopListen();
private:
    static ListenThread lt;
    QTcpServer server;
    QTcpSocket serverSocket;
    unsigned int socketDesriptor = 0;
    ListenThread(unsigned int port);
};

#endif // LISTENTHREAD_H
