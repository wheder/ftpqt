#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    void ftp_disconnect();
    void ftp_connect();

private:
    Ui::MainWindow *ui;
    QFtp *ftp_conn;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void ftpCommandFinished(int commandId, bool error);
    void addToList(const QUrlInfo &urlInfo);
};

#endif // MAINWINDOW_H
