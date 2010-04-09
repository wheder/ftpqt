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
}


void Connection::ftp_connect() {
    ftp_disconnect();
    ftp_conn = new QFtp(this);


    connect(ftp_conn, SIGNAL(commandFinished(int,bool)), this, SLOT(ftpCommandFinished(int,bool)));
    connect(ftp_conn, SIGNAL(listInfo(QUrlInfo)), this, SLOT(addToList(QUrlInfo)));
    //connect(ftp_conn, SIGNAL(dataTransferProgress(qint64,qint64)), this, SLOT(updateDataTransferProgress(qint64,qint64)));
    QUrl url(ui->serverAddress->text());
    ftp_conn->connectToHost(ui->serverAddress->text(), 21);


    if (ui->anonymousConnection->isChecked()) ftp_conn->login();
    else ftp_conn->login(ui->user->text(), ui->password->text());
    ui->statusLabel->setText(tr("Connecting to FTP server '%1'").arg(ui->serverAddress->text()));
}

void Connection::ftpCommandFinished(int, bool error)
{
    if (ftp_conn->currentCommand() == QFtp::ConnectToHost) {
        if (error) {
            QMessageBox::information(this, tr("FTP"),
                                     tr("Unable to connect to the FTP server "
                                        "at '%1'")
                                     .arg(ui->serverAddress->text()));
            ftp_disconnect();
            return;
        }
        ui->statusLabel->setText(tr("Logged onto %1.")
                             .arg(ui->serverAddress->text()));


        panel->show();
        this->hide();

        //downloadButton->setDefault(true);
        //connectButton->setEnabled(true);
        return;
    }
//![6]

//![7]
    if (ftp_conn->currentCommand() == QFtp::Login) {
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
    else if (ftp_conn->currentCommand() == QFtp::List) {
    }
//![9]

}

void Connection::addToList(const QUrlInfo &urlInfo)
{
    panel->addItemFTP(urlInfo);
}



