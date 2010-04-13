#include <QtNetwork>
#include <stdlib.h>
#include "tcpserver.h"
#include "connectiondata.h"

TCPServer::TCPServer() {

    tcpServer = new QTcpServer(this);
    tcpServerData = new QTcpServer(this);

    if (!tcpServer->listen((QHostAddress) "localhost", (quint16) 21)) {
        qDebug()<<QString("cannot listen on port 21");
        return;
    }

    if (!tcpServerData->listen((QHostAddress) "localhost", (quint16) 10260)) {
        qDebug()<<QString("cannot listen on port 10260");
        return;
    }

    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(displayRequest()));
    connect(tcpServerData, SIGNAL(newConnection()), this, SLOT(dataSocketConnected()));

    qDebug()<<QString("listening");
}

void TCPServer::dataSocketConnected(){
    qDebug()<<QString("datasocket connected");
    clientConnectionData = tcpServerData->nextPendingConnection();
    connect(clientConnectionData, SIGNAL(disconnected()),
            clientConnectionData, SLOT(deleteLater()));
    connect(clientConnectionData, SIGNAL(disconnected()),
            this, SLOT(disconnected()));

    connect(clientConnectionData, SIGNAL(readyRead()), this, SLOT(readData()));

    QByteArray d = "";
    //d.append("public_html \r\n");
    //d.append("public2_html \r\n");
   // d.append("public3_html \r\n");
   // d.append("+i8388621.48598,m824253270,r,s612, 514.html \r\n");
    d.append("-rwx------   3 slacker    users         104 Jul 27 01:45 public2_html \r\n");
    d.append("drwx------   3 slacker    users         104 Jul 27 01:45 public3_html \r\n");
    //s->write(d);
    //s->disconnect();

   // QByteArray b = "";
   // b.append("226 Transfer complete. \r\n");
   // clientConnection->write(b);
}


void TCPServer::displayRequest(){
    qDebug()<<QString("connected");

    QByteArray block = "";
    block.append("220 Hello, this is the ftpserver. \r\n");

    clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, SIGNAL(disconnected()),
            clientConnection, SLOT(deleteLater()));
    connect(clientConnection, SIGNAL(disconnected()),
            this, SLOT(disconnected()));

    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readData()));

    clientConnection->write(block);

    //clientConnection->disconnectFromHost();
}

void TCPServer::disconnected() {
    qDebug()<<QString("disconnected");
}

void TCPServer::dataConnected() {
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(this->sender());
    qDebug()<<QString("data connected");
    QByteArray d = "";
    d.append("-rwx------   3 slacker    users         104 Jul 27 01:45 public_html \r\n");
    d.append("-rwx------   3 slacker    users         104 Jul 27 01:45 public2_html \r\n");
    d.append("-rwx------   3 slacker    users         104 Jul 27 01:45 public3_html \r\n");
    d.append("-rwx------   3 slacker    users         104 Jul 27 01:45 public4_html \r\n");
    socket->write(d);

    QByteArray b = "";
    d.append("226 Transfer complete. \r\n");
    clientConnection->write(d);
}

void TCPServer::readData() {
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(this->sender());

    QByteArray block = socket->readAll();
    qDebug()<< QString(block);

    QList<QByteArray> args = block.split(' ');
    QString command = args.takeFirst();
    QString param;

    if(args.length() > 0) {
        param = args.takeFirst();
    }

    if(command.trimmed().toUpper() == "USER") {
        qDebug()<< command;
        qDebug()<< param;
        QByteArray b = "";
        b.append("230 Logged in! \r\n");
        socket->write(b);
    } else if(command.trimmed().toUpper() == "PASS") {
        qDebug()<< command;
        QByteArray b = "";
        b.append("230 Logged in! \r\n");
        socket->write(b);        
    } else if(command.trimmed().toUpper() == "PASV") {
        qDebug()<< command;
        QByteArray b = "";
        b.append("227 Entering Passive Mode (127,0,0,1,40,20). \r\n");
        socket->write(b);
    } else if(command.trimmed().toUpper() == "PWD") {
        qDebug()<< command;
        QByteArray b = "";
        b.append("257 \"/\" is your current location \r\n");
        socket->write(b);
    } else if(command.trimmed().toUpper() == "FEAT") {
        qDebug()<< command;
        QByteArray b = "";
        b.append("211-Extensions supported: \r\n");
        b.append("211 END \r\n");
        socket->write(b);
    } else if(command.trimmed().toUpper() == "RETR") {
        qDebug()<< command;

        QByteArray b = "";
        b.append("150 Accepted data connection \r\n");
        b.append("150 32 bytes to download \r\n");
        socket->write(b);

        sendFile(clientConnectionData, QString("test.txt"));
        clientConnectionData->disconnectFromHost();

        //QByteArray d = "";
        //d.append("hello, this is a test file \r\n");
        //clientConnectionData->write(d);
        //clientConnectionData->disconnectFromHost();

        b = "";
        b.append("226 File successfully transferred \r\n");
        socket->write(b);
    } else if(command.trimmed().toUpper() == "SYST") {
        qDebug()<< command;
        QByteArray b = "";
        b.append("215 UNIX Type: L8 \r\n");
        socket->write(b);
    } else if(command.trimmed().toUpper() == "LIST") {
        qDebug()<< command;
        qDebug()<< QString::number(socket->socketDescriptor());
        //ConnectionData c = findConnectionData(socket->socketDescriptor());

        QByteArray b = "";
        b.append("150 Opening ASCII mode data connection for file list. \r\n");
        socket->write(b);


        QByteArray d = "";
        d.append("-rwx------   3 slacker    users         104 Jul 27 01:45 public2_html.txt \r\n");
        d.append("drwx------   3 slacker    users         104 Jul 27 01:45 public3_html \r\n");

        clientConnectionData->write(d);
        clientConnectionData->disconnectFromHost();

        /*QTcpSocket* dataSocket = new QTcpSocket(this);
        connect(dataSocket, SIGNAL(disconnected()),
                dataSocket, SLOT(deleteLater()));
        connect(dataSocket, SIGNAL(disconnected()),
                this, SLOT(disconnected()));
        connect(dataSocket, SIGNAL(readyRead()), this, SLOT(readData()));
        connect(dataSocket, SIGNAL(connected()), this, SLOT(dataConnected()));

        dataSocket->connectToHost("127.0.0.1", c.getPort());
        */
        /*
        QTcpSocket* _dataSocket = new QTcpSocket(this);
        _dataSocket->connectToHost(c.getIp(), c.getPort());
        if (!_dataSocket->waitForConnected(1000))
        {
           qDebug() << "cannot connect to: " << c.getIp() << "port :" << c.getPort();
        }
        else
        {
           qDebug() << "connected to: " <<  c.getIp() << "port :" << c.getPort();
           QByteArray d = "";
           d.append("drwx------   3 slacker    users         104 Jul 27 01:45 public_html \r\n");
           d.append("drwx------   3 slacker    users         104 Jul 27 01:45 public2_html \r\n");
           d.append("drwx------   3 slacker    users         104 Jul 27 01:45 public3_html \r\n");
           _dataSocket->write(d);

        }
        */
        b = "";
        b.append("226 Transfer complete. \r\n");
        socket->write(b);

    } else if(command.trimmed().toUpper() == "PORT") {
        qDebug()<< command;
        param.trimmed();
        qDebug()<< param;

        QList<QString> a = param.split(',');
        if(a.length() == 6) {
            QString ip1 = a.takeFirst();
            QString ip2 = a.takeFirst();
            QString ip3 = a.takeFirst();
            QString ip4 = a.takeFirst();
            QString p1 = a.takeFirst();
            QString p2 = a.takeFirst();
            QString ip = ip1 + "." + ip2 + "." + ip3 + "." + ip4;
            int port = p1.toDouble() * 256 + p2.toDouble();
            qDebug()<< p1+":"+p2;
            qDebug()<< ip+":"+ QString::number(port);

            ConnectionData* data = new ConnectionData(socket->socketDescriptor(), ip, (quint16) port);
            connectionData.append(*data);
/*
            QTcpSocket* dataSocket = new QTcpSocket(this);
            connect(dataSocket, SIGNAL(disconnected()),
                    dataSocket, SLOT(deleteLater()));
            connect(dataSocket, SIGNAL(disconnected()),
                    this, SLOT(disconnected()));
            connect(dataSocket, SIGNAL(readyRead()), this, SLOT(readData()));
            dataSocket->connectToHost(ip, port);
*/
            QByteArray b = "";
            b.append("200 PORT command successful. \r\n");
            socket->write(b);
        }
    } else if(command.trimmed().toUpper() == "TYPE") {
        qDebug()<< command;
        qDebug()<< param;
        if(param.trimmed().toUpper() == "I") {
            QByteArray b = "";
            b.append("200 TYPE is now 8-bit binary \r\n");
            socket->write(b);
        } else if(param.trimmed().toUpper() == "A") {
            QByteArray b = "";
            b.append("200 TYPE is now ASCII \r\n");
            socket->write(b);
        } else {
            QByteArray b = "";
            b.append("Command not implemented. \r\n");
            socket->write(b);
        }
    } else {
        qDebug()<< command;
        QByteArray b = "";
        b.append("500 Syntax error, command unrecognized. \r\n");
        socket->write(b);
    }
}

void TCPServer::sendFile(QTcpSocket *tcpclient, QString filename) {
    QFile file(filename);

    QByteArray block;
    if(!(file.open(QIODevice::ReadOnly)))
        qDebug()<< "read only file";

    QDataStream out(&block, QIODevice::WriteOnly);
    //out.setVersion(QDataStream::Qt_4_0);
    //out << (quint16)0;

    while (!file.atEnd()) {
        QByteArray line = file.readAll();
        //QString om(line);
        //out<<om;
        out<<line;
        //out.device()->seek(0);
        //out << (quint16)(block.size() - sizeof(quint16));
        tcpclient->write(line);
    }
    file.close();
}

ConnectionData TCPServer::findConnectionData(int sd) {
    qDebug()<< QString::number(sd);

    QList<ConnectionData>::const_iterator i;
    for (i = connectionData.constBegin(); i != connectionData.constEnd(); ++i) {
         ConnectionData c = *i;
         if(sd == c.getSocketDescriptor()) {
             return c;
         }
    }
}
