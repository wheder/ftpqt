#include "connection.h"
#include "ui_connection.h"
#include <QtGui/QMessageBox>
#include <cstdio>
#include <iostream>


Connection::Connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connection)
{
    ui->setupUi(this);
    ftp_conn = new QxFtp(this);
    all_connections.append(ftp_conn);
    panel = new Panel();
    panel->setFTPConn(&ftp_conn);
    max_connections = ui->maxConnections->value();
    connect(ui->anonymousConnection, SIGNAL(stateChanged(int)), this, SLOT(anonymousChanged(int)));
    connect(panel, SIGNAL(newTransferQueueItemCreated(TransferQueueItem*)), this, SLOT(addItemToTransferQueue(TransferQueueItem*)));
    connect(panel, SIGNAL(canTransferNow()), this, SLOT(setupTransfers()));
    connect(panel, SIGNAL(canTransfer(QxFtp*)), this, SLOT(queueCheckedFirst(QxFtp*)));
}

Connection::~Connection()
{
    delete ui;
}

void Connection::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Connection::on_buttonBox_accepted()
{
    ftp_connect();
}

void Connection::on_buttonBox_rejected()
{
    ftp_disconnect();
    exit(0);
}


void Connection::ftp_disconnect() {
    ftp_conn->abort();
    //ftp_conn->close();
    panel->hide();
    this->show();
}
void Connection::startTransfer(QxFtp * conn ,TransferQueueItem * itemToTransfer){
    if (itemToTransfer->isDownload()) {
        QFile * file = new QFile(itemToTransfer->getLocalDir()+QString("/")+itemToTransfer->getFileName());
        if (!file->open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Cannot open file '%1' for reading!").arg(itemToTransfer->getFileName()));
            return;
        }


        itemToTransfer->setId(conn->get(itemToTransfer->getFtpDir()+QString("/")+itemToTransfer->getFileName(), file));
        pendingQueue.append(itemToTransfer);
        itemToTransfer->connectFtp(conn);
    }
    else {
        QFile * file = new QFile(itemToTransfer->getLocalDir()+QString("/")+itemToTransfer->getFileName());
        if (!file->open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Cannot open file '%1' for reading!").arg(itemToTransfer->getFileName()));
            return;
        }


        itemToTransfer->setId(conn->put(file, itemToTransfer->getFtpDir()+QString("/")+itemToTransfer->getFileName()));
        pendingQueue.append(itemToTransfer);
        itemToTransfer->connectFtp(conn);

    }

}

void Connection::ftp_connect() {
    ftp_disconnect();
    max_connections = ui->maxConnections->value();

    connect(ftp_conn, SIGNAL(x_commandFinished(QxFtp *,int,bool)), this, SLOT( ftpCommandFinished(QxFtp *,int,bool)));
    connect(ftp_conn, SIGNAL(x_commandStarted(QxFtp *,int)), this, SLOT(ftpCommandStarted(QxFtp *,int)));
    connect(ftp_conn, SIGNAL(x_listInfo(QxFtp *,QUrlInfo)), this, SLOT(addToList(QxFtp *,QUrlInfo)));
    connect(ftp_conn, SIGNAL(x_rawCommandReply(QxFtp *,int, const QString &)), this, SLOT(ftp_rawCommandReply(QxFtp *,int, const QString &)) );
    QUrl url(ui->serverAddress->text());
    ftp_conn->connectToHost(ui->serverAddress->text(), 21);


    if (ui->anonymousConnection->isChecked()) ftp_conn->login();
    else ftp_conn->login(ui->user->text(), ui->password->text());
    ui->statusLabel->setText(tr("Connecting to FTP server '%1'").arg(ui->serverAddress->text()));
}

void Connection::ftpCommandStarted(QxFtp * a, int id)
{
emit setupTransfers();

}

void Connection::ftpCommandFinished(QxFtp * origin, int id, bool error)
{

    //std::cout<< "finished command id"<<id <<std::endl;

    if (origin->currentCommand() != QxFtp::RawCommand && origin->currentCommand() != QxFtp::Put && origin->currentCommand() != QxFtp::Get) pwd();
    //ta svina se zacyklila...
    if (error) {
        std::cerr<< "State: "<<origin->state() <<std::endl;
        std::cerr<< "Error: "<<origin->errorString().toStdString() <<std::endl;
    }

    if (origin->currentCommand() == QxFtp::ConnectToHost) {
        if (error) {
            QMessageBox::information(this, tr("FTP"),
                                     tr("Unable to connect to the FTP server "
                                        "at '%1'<br />%2")
                                     .arg(ui->serverAddress->text()).arg(origin->errorString()));
            ftp_disconnect();
            return;
        }
        ui->statusLabel->setText(tr("Connected to %1.")
                             .arg(ui->serverAddress->text()));


        panel->show();
        connect( this, SIGNAL(pwdChanged(const QString &)), panel, SLOT(changePwd(const QString &)) );
        this->hide();

        //downloadButton->setDefault(true);
        //connectButton->setEnabled(true);
        return;
    }


//![6]

//![7]
    if (origin->currentCommand() == QxFtp::Login) {
        if (error) {
            QMessageBox::information(this, tr("FTP"),
                                     tr("Unable to login to the FTP server:<br />%1")
                                     .arg(origin->errorString()));
            ui->statusLabel->setText(tr("Disconnected from %1.")
                                 .arg(ui->serverAddress->text()));
            ftp_disconnect();
            return;
        }
        if (origin == ftp_conn)origin->list();

    }
    else if (origin->currentCommand() == QxFtp::Mkdir) {
        //std::cout<<"created"<<std::endl;
        //ftp_conn->list();
    }
    else if (origin->currentCommand() == QxFtp::List) {
    }
    else if (origin->currentCommand() == QxFtp::Rename) {
        if (error) {
            QMessageBox::critical(this, tr("Error!"),
                                     tr("'%1'")
                                     .arg(origin->errorString()));
            origin->list();
        }
    }
    else if (origin->currentCommand() == QxFtp::Put || origin->currentCommand() == QxFtp::Get) {
        for (int i = 0 ; i < pendingQueue.size() ; i++)
        {
            if (origin == pendingQueue.at(i)->conn())
            {
                pendingQueue.at(i)->deleteLater();
                pendingQueue.removeAt(i);
                break;
            }
        }

    }


    emit setupTransfers();


}

void Connection::addToList(QxFtp * origin, const QUrlInfo &urlInfo)
{
    panel->addItemFTP(urlInfo);
}


void Connection::ftp_rawCommandReply( QxFtp * origin, int code, const QString &text )
{
    if ( code == 257 ) {
        QString pwd;
        pwd = text.section( '"', 1, 1 );
        emit pwdChanged(pwd);

    }
}


void Connection::pwd() {
    ftp_conn->rawCommand("PWD");
}
void Connection::anonymousChanged(int newState) {
    if (newState == Qt::Unchecked) {
        ui->password->setEnabled(true);
        ui->user->setEnabled(true);
    }
    else {
        ui->password->setEnabled(false);
        ui->user->setEnabled(false);
    }
}
void Connection::addItemToTransferQueue(TransferQueueItem * item) {
    transferQueue.append(item);
}

void Connection::queueCheckedFirst(QxFtp * connection) {
    connect(this, SIGNAL(canTransfer(QxFtp*)), this, SLOT(queueChecked(QxFtp*)));
    emit setupTransfers();
}
void Connection::queueChecked(QxFtp * connection) {
    if (!transferQueue.isEmpty()) {
        TransferQueueItem * item = transferQueue.takeFirst();       


        for (int i=0; i< all_connections.size(); i++) {
            if (all_connections.at(i) == connection) {
                //qDebug()<<"vlakno "<<i << "checkuje queue " << item->getFileName();
            }
            else {
                //qDebug()<<"vlakno "<<i << "NEcheckuje queue. dela toto: " <<  all_connections.at(i)->currentCommand();
            }
        }




        startTransfer(connection,item);
        //queueChecked(connection);//takhle si kazdy blbec bude nacitat dokud to pujde ;-)
    }
}
void Connection::setupTransfers() {
    //staci nam vytvorit jeden, dalsi se vytvori pri dalsich krocich

    if (ftp_conn->state() != QxFtp::LoggedIn) return;
    while (all_connections.size() < max_connections) {
        qDebug("creating new connection");
        QxFtp * another_conn = new QxFtp(this);

        connect(another_conn, SIGNAL(x_commandFinished(QxFtp *,int,bool)), this, SLOT(ftpCommandFinished(QxFtp *,int,bool)));
        connect(another_conn, SIGNAL(x_commandStarted(QxFtp *,int)), this, SLOT(ftpCommandStarted(QxFtp *,int)));
        connect(another_conn, SIGNAL(x_listInfo(QxFtp *,QUrlInfo)), this, SLOT(addToList(QxFtp *,QUrlInfo)));
        connect(another_conn, SIGNAL(x_rawCommandReply(QxFtp *,int, const QString &)), this, SLOT(ftp_rawCommandReply(QxFtp *,int, const QString &)) );
        QUrl url(ui->serverAddress->text());
        another_conn->connectToHost(ui->serverAddress->text(), 21);


        if (ui->anonymousConnection->isChecked()) another_conn->login();
        else another_conn->login(ui->user->text(), ui->password->text());

        all_connections.append(another_conn);
    }
    for (int i=0; i< all_connections.size(); i++) {
        if (!all_connections.at(i)->hasPendingCommands() && all_connections.at(i)->currentCommand() == QxFtp::None) {
            //bool ok = true;
            //for (int l = 0; l<pendingQueue.size(); l++)
            //if (pendingQueue.at(l)->conn() == all_connections.at(i)) ok = false;
            //if (ok) emit canTransfer(all_connections.at(i));

            //queueChecked(all_connections.at(i));
            emit canTransfer(all_connections.at(i));
        }
    }





}
