#ifndef TCPSERVER_H
#define TCPSERVER_H


#include <QObject>
#include <QList>
#include "connectiondata.h"

QT_BEGIN_NAMESPACE
class QTcpServer;
class QTcpSocket;
QT_END_NAMESPACE

class TCPServer : public QObject
{

    Q_OBJECT

public:
    TCPServer();
    ConnectionData findConnectionData(int sd);
    void sendFile(QTcpSocket *tcpclient, QString filename);
private slots:
    void displayRequest();
    void dataSocketConnected();
    void readData();
    void disconnected();
    void dataConnected();    
private:
    QTcpServer *tcpServer;
    QTcpServer *tcpServerData;
    QTcpSocket *clientConnection;
    QTcpSocket *clientConnectionData;
    QList<ConnectionData> connectionData;
};

#endif // TCPSERVER_H
