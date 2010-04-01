#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtNetwork>
#include <QtGui/QMessageBox>
#include <cstdio>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ftp_conn = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_buttonBox_rejected()
{
    ftp_disconnect();
    exit(0);
}

void MainWindow::on_buttonBox_accepted()
{
    ftp_connect();
}

void MainWindow::ftp_disconnect() {
    if (!ftp_conn) return;
    ftp_conn->abort();
    ftp_conn->deleteLater();
    ftp_conn = 0;
}

void MainWindow::ftp_connect() {
    ftp_disconnect();
    ftp_conn = new QFtp(this);
    connect(ftp_conn, SIGNAL(commandFinished(int,bool)), this, SLOT(ftpCommandFinished(int,bool)));
    connect(ftp_conn, SIGNAL(listInfo(QUrlInfo)), this, SLOT(addToList(QUrlInfo)));
    //connect(ftp_conn, SIGNAL(dataTransferProgress(qint64,qint64)), this, SLOT(updateDataTransferProgress(qint64,qint64)));
    QUrl url(ui->serverAddress->text());
    ftp_conn->connectToHost(ui->serverAddress->text(), 21);
    if (ui->anonymousConnection->isChecked()) ftp_conn->login();
    else ftp_conn->login(ui->user->text(), ui->password->text());
    ui->statusLabel->setText(tr("Pripojování k FTP serveru %1").arg(ui->serverAddress->text()));
}


void MainWindow::ftpCommandFinished(int, bool error)
{
    if (ftp_conn->currentCommand() == QFtp::ConnectToHost) {
        if (error) {
            QMessageBox::information(this, tr("FTP"),
                                     tr("Unable to connect to the FTP server "
                                        "at %1. Please check that the host "
                                        "name is correct.")
                                     .arg(ui->serverAddress->text()));
            ftp_disconnect();
            return;
        }
        ui->statusLabel->setText(tr("Logged onto %1.")
                             .arg(ui->serverAddress->text()));
        //fileList->setFocus();
        //downloadButton->setDefault(true);
        //connectButton->setEnabled(true);
        return;
    }
//![6]

//![7]
    if (ftp_conn->currentCommand() == QFtp::Login) {
        ftp_conn->list();
        std::cout << "------------------"<<std::endl;
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
    } else if (ftp->currentCommand() == QFtp::List) {
        if (isDirectory.isEmpty()) {
            fileList->addTopLevelItem(new QTreeWidgetItem(QStringList() << tr("<empty>")));
            fileList->setEnabled(false);
        }
    }
//![9]
*/
}




void MainWindow::addToList(const QUrlInfo &urlInfo)
{
    std::cout<<urlInfo.name().toStdString()<<std::endl;

    /*
    //QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, urlInfo.name());
    item->setText(1, QString::number(urlInfo.size()));
    item->setText(2, urlInfo.owner());
    item->setText(3, urlInfo.group());
    item->setText(4, urlInfo.lastModified().toString("MMM dd yyyy"));

    //QPixmap pixmap(urlInfo.isDir() ? ":/images/dir.png" : ":/images/file.png");
    item->setIcon(0, pixmap);

    isDirectory[urlInfo.name()] = urlInfo.isDir();
    fileList->addTopLevelItem(item);
    if (!fileList->currentItem()) {
        fileList->setCurrentItem(fileList->topLevelItem(0));
        fileList->setEnabled(true);
    }
    */
}

