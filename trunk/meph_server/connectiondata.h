#ifndef CONNECTIONDATA_H
#define CONNECTIONDATA_H

#include <QObject>

class ConnectionData
{


public:
    ConnectionData(int sd, QString ip, quint16 port);
    void setWorkingDirectory(QString str);
    void setSocketDescriptorData(int sd);
    int getSocketDescriptor();
    int getSocketDescriptorData();
    QString getIp();
    quint16 getPort();
    QString getWorkingDirectory();
private:
    int socketDescriptor;
    int socketDescriptorData;
    QString ip;
    quint16 port;
    QString workingDirectory;
};

#endif // CONNECTIONDATA_H
