#ifndef QXFTP_H
#define QXFTP_H

#include <QFtp>
#include <QObject>

class QxFtp : public QFtp
{
    Q_OBJECT
public:
    explicit QxFtp(QObject * parent =0);
    QxFtp(const QxFtp &);
    virtual ~QxFtp();


private:
    void init_connects();


signals:
    void x_stateChanged(QxFtp*, int);
    void x_listInfo(QxFtp*, const QUrlInfo&);
    void x_readyRead(QxFtp* a);
    void x_dataTransferProgress(QxFtp*, qint64, qint64);
    void x_rawCommandReply(QxFtp*, int, const QString&);

    void x_commandStarted(QxFtp*, int);
    void x_commandFinished(QxFtp*, int, bool);
    void x_done(QxFtp*, bool);
private slots:
    void old_stateChanged(int);
    void old_listInfo(const QUrlInfo&);
    void old_readyRead();
    void old_dataTransferProgress(qint64, qint64);
    void old_rawCommandReply(int, const QString&);

    void old_commandStarted(int);
    void old_commandFinished(int, bool);
    void old_done(bool);





};

#endif // QXFTP_H
