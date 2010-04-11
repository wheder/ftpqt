#include "queueitem.h"

QueueItem::QueueItem(QHostAddress targetAddress, QString command);
{
    simpleCommand = true;
    this.targetAddress = targetAddress;
    this.command = command;
}

QueueItem::QueueItem(QHostAddress targetAddress, QString command, QFile fileName, bool upload, unsigned int lastByte, unsigned int countBytes)
{
    simpleCommand = false;
    this.targetAddress = targetAddress;
    this.command = command;
    this.fileName = fileName;
    if(command.contains("put", Qt::CaseInsensitive)){
        upload = true;
    } else {
        upload = false;
    }
    this.countBytes = countBytes;
    lastByte = 0;
}

bool QueueItem::isSimpleCommand()
{
    return simpleCommand;
}

unsigned int QueueItem::lastProcessedByte()
{
    return lastByte;
}

void QueueItem::setProcessedByte(unsigned int index)
{
    lastByte = index;
}
