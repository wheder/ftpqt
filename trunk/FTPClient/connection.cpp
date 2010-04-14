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
    ftp_conn = NULL;
    panel = new Panel();
    panel->setFTPConn(&ftp_conn);
    connect(ui->anonymousConnection, SIGNAL(stateChanged(int)), this, SLOT(anonymousChanged(int)));
    connect(panel, SIGNAL(newTransferQueueItemCreated(TransferQueueItem*)), this, SLOT(addItemToTransferQueue(TransferQueueItem*)));
    connect(panel, SIGNAL(canTransfer(QFtp*)), this, SLOT(queueChecked(QFtp*)));
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
    if (!ftp_conn) return;
    ftp_conn->abort();
    ftp_conn->deleteLater();
    ftp_conn = NULL;
    panel->hide();
    this->show();
}
void Connection::startTransfer(QFtp * conn ,TransferQueueItem * itemToTransfer){

    QFile * file = new QFile(itemToTransfer->getLocalDir()+QString("/")+itemToTransfer->getFileName());
    if (!file->open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Cannot open file '%1' for reading!").arg(itemToTransfer->getFileName()));
        return;
    }
    Command command;

    command.id = conn->put(file, itemToTransfer->getFtpDir()+QString("/")+itemToTransfer->getFileName());
    command.itemToTransfer = itemToTransfer;
    doneQueue.append(command);

}

void Connection::ftp_connect() {
    ftp_disconnect();
    ftp_conn = new QFtp(this);


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
    if (ftp_conn->currentCommand() == QFtp::Put) {
        Command command;
        for (int i = 0 ; i < doneQueue.size() ; i++)
        {
            command = doneQueue.at(i);
            if (command.id == id)
            {
                connect(ftp_conn, SIGNAL(dataTransferProgress(qint64,qint64)), command.itemToTransfer, SLOT(updateProgress(qint64,qint64)));
                break;
            }
        }
    }
}

void Connection::ftpCommandFinished(int id, bool error)
{

    if (ftp_conn->currentCommand() != QFtp::RawCommand) pwd();
    //ta svina se zacyklila...

    if (error) {
        std::cerr<< "Error: "<<ftp_conn->errorString().toStdString() <<std::endl;
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
            ui->statusLabel->setText(tr("Disonnected from %1.")
                                 .arg(ui->serverAddress->text()));
            ftp_disconnect();
            return;
        }
        ftp_conn->list();

    }
//![7]
/*
//![8]
    if (ftp->currentCommand() == QFtp::Get) {
        if (error) {
            statusLabel->setText(tr("Canceled download of %1.")
                                 .arg(file->fileName()));
            file->close();
            file->remove();
        } else {
            statusLabel->setText(tr("Downloaded %1 to current directory.")
                                 .arg(file->fileName()));
            file->close();
        }
        delete file;
        enableDownloadButton();
        progressDialog->hide();
//![8]
//![9]
    }
    */
    else if (ftp_conn->currentCommand() == QFtp::Mkdir) {
        std::cout<<"created"<<std::endl;        
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


        Command command;
        for (int i = 0 ; i < doneQueue.size() ; i++)
        {
            command = doneQueue.at(i);
            if (command.id == id)
            {
                disconnect(ftp_conn, SIGNAL(dataTransferProgress(qint64,qint64)), command.itemToTransfer, SLOT(updateProgress(qint64,qint64)));
                delete command.itemToTransfer;
                doneQueue.removeAt(i);
                break;
            }
        }

    }
//![9]

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
        startTransfer(connection,item);
        //queueChecked(connection);//takhle si kazdy blbec bude nacitat dokud to pujde ;-)
    }
}
