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
    ftp_conn = new QFtp(this);
    all_connections.append(ftp_conn);
    panel = new Panel();
    panel->setFTPConn(&ftp_conn);
    max_connections = ui->maxConnections->value();
    connect(ui->anonymousConnection, SIGNAL(stateChanged(int)), this, SLOT(anonymousChanged(int)));
    connect(panel, SIGNAL(newTransferQueueItemCreated(TransferQueueItem*)), this, SLOT(addItemToTransferQueue(TransferQueueItem*)));
    connect(panel, SIGNAL(canTransfer(QFtp*)), this, SLOT(queueChecked(QFtp*)));
    connect(this, SIGNAL(canTransfer(QFtp*)), this, SLOT(queueChecked(QFtp*)));
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
void Connection::startTransfer(QFtp * conn ,TransferQueueItem * itemToTransfer){

    QFile * file = new QFile(itemToTransfer->getLocalDir()+QString("/")+itemToTransfer->getFileName());
    if (!file->open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Cannot open file '%1' for reading!").arg(itemToTransfer->getFileName()));
        return;
    }


    itemToTransfer->setId(conn->put(file, itemToTransfer->getFtpDir()+QString("/")+itemToTransfer->getFileName()));
    pendingQueue.append(itemToTransfer);
    itemToTransfer->connectFtp(conn);

}

void Connection::ftp_connect() {
    ftp_disconnect();
    max_connections = ui->maxConnections->value();

    connect(ftp_conn, SIGNAL(commandFinished(int,bool)), this, SLOT(ftpCommandFinished(int,bool)));
    connect(ftp_conn, SIGNAL(commandStarted(int)), this, SLOT(ftpCommandStarted(int)));
    connect(ftp_conn, SIGNAL(listInfo(QUrlInfo)), this, SLOT(addToList(QUrlInfo)));  
    connect(ftp_conn, SIGNAL(rawCommandReply(int, const QString &)), this, SLOT(ftp_rawCommandReply(int, const QString &)) );
    QUrl url(ui->serverAddress->text());
    ftp_conn->connectToHost(ui->serverAddress->text(), 21);


    if (ui->anonymousConnection->isChecked()) ftp_conn->login();
    else ftp_conn->login(ui->user->text(), ui->password->text());
    ui->statusLabel->setText(tr("Connecting to FTP server '%1'").arg(ui->serverAddress->text()));
}

void Connection::ftpCommandStarted(int id)
{
    setupTransfers();

}

void Connection::ftpCommandFinished(int id, bool error)
{

    std::cout<< "finished command id"<<id <<std::endl;

    if (ftp_conn->currentCommand() != QFtp::RawCommand) pwd();
    //ta svina se zacyklila...
    if (error) for (int i=0; i< all_connections.size(); i++) {
        std::cerr<< i<<":_____________________" <<std::endl;
        std::cerr<< "State: "<<all_connections.at(i)->state() <<std::endl;
        std::cerr<< "Error: "<<all_connections.at(i)->errorString().toStdString() <<std::endl;
        std::cerr<< "_____________________" <<std::endl;
    }

    if (ftp_conn->currentCommand() == QFtp::ConnectToHost) {
        if (error) {
            QMessageBox::information(this, tr("FTP"),
                                     tr("Unable to connect to the FTP server "
                                        "at '%1'<br />%2")
                                     .arg(ui->serverAddress->text()).arg(ftp_conn->errorString()));
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
    if (ftp_conn->currentCommand() == QFtp::Login) {
        if (error) {
            QMessageBox::information(this, tr("FTP"),
                                     tr("Unable to login to the FTP server:<br />%1")
                                     .arg(ftp_conn->errorString()));
            ui->statusLabel->setText(tr("Disconnected from %1.")
                                 .arg(ui->serverAddress->text()));
            ftp_disconnect();
            return;
        }
        ftp_conn->list();

    }
    else if (ftp_conn->currentCommand() == QFtp::Mkdir) {
        //std::cout<<"created"<<std::endl;
        //ftp_conn->list();
    }
    else if (ftp_conn->currentCommand() == QFtp::List) {
    }
    else if (ftp_conn->currentCommand() == QFtp::Rename) {
        if (error) {
            QMessageBox::critical(this, tr("Error!"),
                                     tr("'%1'")
                                     .arg(ftp_conn->errorString()));
            ftp_conn->list();
        }
    }
    else if (ftp_conn->currentCommand() == QFtp::Put || ftp_conn->currentCommand() == QFtp::Get) {



    }


    for (int i = 0 ; i < pendingQueue.size() ; i++)
    {
        if (id == pendingQueue.at(i)->getId() && pendingQueue.at(i)->conn()->currentCommand() == QFtp::Put)
        {
            delete pendingQueue.at(i);
            pendingQueue.removeAt(i);
            break;
        }
    }


}

void Connection::addToList(const QUrlInfo &urlInfo)
{
    panel->addItemFTP(urlInfo);
}


void Connection::ftp_rawCommandReply( int code, const QString &text )
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
void Connection::queueChecked(QFtp * connection) {
    while (!transferQueue.isEmpty()) {
        TransferQueueItem * item = transferQueue.takeFirst();       


        for (int i=0; i< all_connections.size(); i++) {
            if (all_connections.at(i) == connection) {
                qDebug()<<"vlakno "<<i << "checkuje queue";
            }
        }




        startTransfer(connection,item);
        //queueChecked(connection);//takhle si kazdy blbec bude nacitat dokud to pujde ;-)
    }
}
void Connection::setupTransfers() {
    //staci nam vytvorit jeden, dalsi se vytvori pri dalsich krocich

    if (ftp_conn->state() != QFtp::LoggedIn) return;
    if (all_connections.size() < max_connections) {
        qDebug("creating new connection");
        QFtp * another_conn = new QFtp(this);

        connect(another_conn, SIGNAL(commandFinished(int,bool)), this, SLOT(ftpCommandFinished(int,bool)));
        connect(another_conn, SIGNAL(commandStarted(int)), this, SLOT(ftpCommandStarted(int)));
        connect(another_conn, SIGNAL(listInfo(QUrlInfo)), this, SLOT(addToList(QUrlInfo)));
        connect(another_conn, SIGNAL(rawCommandReply(int, const QString &)), this, SLOT(ftp_rawCommandReply(int, const QString &)) );
        QUrl url(ui->serverAddress->text());
        another_conn->connectToHost(ui->serverAddress->text(), 21);


        if (ui->anonymousConnection->isChecked()) ftp_conn->login();
        else another_conn->login(ui->user->text(), ui->password->text());

        all_connections.append(another_conn);
    }
    for (int i=0; i< all_connections.size(); i++) {
        if (all_connections.at(i)->currentId() == 0) {
            emit canTransfer(all_connections.at(i));
        }
    }





}
