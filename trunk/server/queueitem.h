#ifndef QUEUEITEM_H
#define QUEUEITEM_H

#include <QObject>
#include <QString>
#include <QHostAddress>
#include <QFile>
#include <QString>

/**
  * Class represent single request. Request are two forms - simple FTP commands (USER, LIST, e.g.) and file commands.
  * File request knows its fileName, last processed byte and its length.
  */

// Co jsem neimplementoval, pze si nejsem jisty jestli to vubec budem delat, kvuli casove tisni je ten signal,
// ktery bude posilat item, ktery uz dlouho ceka ve fronte, aby mu nevyprsel TimeOut, s tim souvisi ten atribut
// lastUpdate. Tak to necham az podle casu, doimplementovani by snad nebylo narocne na zmeny.
class QueueItem : public QObject
{
    Q_OBJECT

public:
    /**
      * Constructor for simple FTP command. Contains host address and string value of command.
      */
    QueueItem(QHostAddress targetAddress, QString command);
    /**
      * Constructor for file FTP command. Contains host address, string value of command, QFile
      * format of file, upload flag, index of last processed byte and count of all bytes.
      */
    QueueItem(QHostAddress targetAddress, QString command, QFile fileName, bool upload, unsigned int lastByte, unsigned int countBytes);
    /**
      * Testing of type item - simple command or file-request.
      */
    bool isSimpleCommand();
    /**
      * Return index of last sent / received byte of file.
      */
    unsigned int lastProcessedByte();
    /**
      * Set index of last processed byte to new value.
      */
    void setProcessedByte(int index);

signals:
    //void needRefresh(;

private:
    /**
      * Target address for actual QueueItem.
      */
    QHostAddress targetAddress;
    /**
      * Value of FTP command in string form.
      */
    QString command;
    /**
      * Processed file in QFile form.
      */
    QFile fileName;
    /**
      * Upload flag shows direction of transmission.
      */
    bool upload;
    /**
      * Index of last sent / received byte.
      */
    unsigned int lastByte;
    /**
      * Amount of bytes of file.
      */
    unsigned int countBytes;
    /**
      * Flag shows that is not file request.
      */
    bool simpleCommand;
    //unsigned int lastUpdate;
};

#endif // QUEUEITEM_H
