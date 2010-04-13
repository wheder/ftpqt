#include "connectiondata.h"

ConnectionData::ConnectionData(int sd, QString ip, quint16 port) {
    this->socketDescriptor = sd;
    this->ip = ip;
    this->port = port;
    this->workingDirectory = "/";
}

void ConnectionData::setWorkingDirectory(QString str){
    this->workingDirectory = str;
}

void ConnectionData::setSocketDescriptorData(int sd){
    this->socketDescriptorData = sd;
}

QString ConnectionData::getWorkingDirectory() {
    return this->workingDirectory;
}

QString ConnectionData::getIp() {
    return this->ip;
}

quint16 ConnectionData::getPort() {
    return this->port;
}

int ConnectionData::getSocketDescriptor() {
    return this->socketDescriptor;
}

int ConnectionData::getSocketDescriptorData() {
    return this->socketDescriptorData;
}
