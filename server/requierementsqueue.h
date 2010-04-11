#ifndef REQUIEREMENTSQUEUE_H
#define REQUIEREMENTSQUEUE_H

#include <QObject>

class requierementsQueue : public QObject
{
Q_OBJECT
public:
    explicit requierementsQueue(QObject *parent = 0);

signals:
    int state();//full = -1, empty=0, count=n

public slots:
    void push(QObject);
    QObject pop();
    void top();

private:
};

#endif // REQUIEREMENTSQUEUE_H
