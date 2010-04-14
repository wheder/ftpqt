#include "qxftp.h"
#include <QObject>

QxFtp::QxFtp(QObject *parent) :
        QFtp(parent)
{
    init_connects();
}
QxFtp::QxFtp(const QxFtp &) :
        QFtp(this)
{

}
QxFtp::~QxFtp()
{

}
void QxFtp::init_connects(){

    connect(this, SIGNAL(stateChanged(int)), this, SLOT(old_stateChanged(int)));
    connect(this, SIGNAL(listInfo(const QUrlInfo&)), this, SLOT(old_listInfo(const QUrlInfo&)));
    connect(this, SIGNAL(readyRead()), this, SLOT(old_readyRead()));
    connect(this, SIGNAL(dataTransferProgress(qint64, qint64)), this, SLOT(old_dataTransferProgress(qint64, qint64)));
    connect(this, SIGNAL(rawCommandReply(int, const QString&)), this, SLOT(old_rawCommandReply(int, const QString&)));
    connect(this, SIGNAL(commandStarted(int)), this, SLOT(old_commandStarted(int)));
    connect(this, SIGNAL(commandFinished(int, bool)), this, SLOT(old_commandFinished(int, bool)));
    connect(this, SIGNAL(done(bool)), this, SLOT(old_done(bool)));
}
void QxFtp::old_stateChanged(int a) {
    emit x_stateChanged(this, a);
}
void QxFtp::old_listInfo(const QUrlInfo& a){
    emit x_listInfo(this, a);
}

void QxFtp::old_readyRead(){
    emit x_readyRead(this);
}

void QxFtp::old_dataTransferProgress(qint64 a, qint64 b){
    emit x_dataTransferProgress(this, a, b);
}

void QxFtp::old_rawCommandReply(int a, const QString& b){
    emit x_rawCommandReply(this, a, b);
}

void QxFtp::old_commandStarted(int a ){
    emit x_commandStarted(this, a);
}

void QxFtp::old_commandFinished(int a , bool b){
    emit x_commandFinished(this, a, b);
}

void QxFtp::old_done(bool a){
    emit x_done(this, a);

}
