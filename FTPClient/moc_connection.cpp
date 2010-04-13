/****************************************************************************
** Meta object code from reading C++ file 'connection.h'
**
** Created
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "connection.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Connection[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      87,   80,   11,   11, 0x08,
     124,  116,   11,   11, 0x08,
     154,  144,   11,   11, 0x08,
     196,  187,   11,   11, 0x08,
     223,  218,   11,   11, 0x08,
     277,  266,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Connection[] = {
    "Connection\0\0pwdChanged(QString)\0"
    "on_buttonBox_rejected()\0on_buttonBox_accepted()\0"
    ",error\0ftpCommandFinished(int,bool)\0"
    "urlInfo\0addToList(QUrlInfo)\0code,text\0"
    "ftp_rawCommandReply(int,QString)\0"
    "newState\0anonymousChanged(int)\0item\0"
    "addItemToTransferQueue(TransferQueueItem*)\0"
    "connection\0queueChecked(QFtp*)\0"
};

const QMetaObject Connection::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Connection,
      qt_meta_data_Connection, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Connection::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Connection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Connection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Connection))
        return static_cast<void*>(const_cast< Connection*>(this));
    return QDialog::qt_metacast(_clname);
}

int Connection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: pwdChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: on_buttonBox_rejected(); break;
        case 2: on_buttonBox_accepted(); break;
        case 3: ftpCommandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: addToList((*reinterpret_cast< const QUrlInfo(*)>(_a[1]))); break;
        case 5: ftp_rawCommandReply((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: anonymousChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: addItemToTransferQueue((*reinterpret_cast< TransferQueueItem*(*)>(_a[1]))); break;
        case 8: queueChecked((*reinterpret_cast< QFtp*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Connection::pwdChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
