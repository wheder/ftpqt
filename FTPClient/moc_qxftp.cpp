/****************************************************************************
** Meta object code from reading C++ file 'qxftp.h'
**
** Created
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qxftp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxftp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QxFtp[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    7,    6,    6, 0x05,
      36,    7,    6,    6, 0x05,
      66,   64,    6,    6, 0x05,
      89,   86,    6,    6, 0x05,
     134,   86,    6,    6, 0x05,
     172,    7,    6,    6, 0x05,
     201,   86,    6,    6, 0x05,
     236,    7,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     256,    6,    6,    6, 0x08,
     278,    6,    6,    6, 0x08,
     301,    6,    6,    6, 0x08,
     317,    7,    6,    6, 0x08,
     357,    7,    6,    6, 0x08,
     390,    6,    6,    6, 0x08,
     414,    7,    6,    6, 0x08,
     444,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QxFtp[] = {
    "QxFtp\0\0,\0x_stateChanged(QxFtp*,int)\0"
    "x_listInfo(QxFtp*,QUrlInfo)\0a\0"
    "x_readyRead(QxFtp*)\0,,\0"
    "x_dataTransferProgress(QxFtp*,qint64,qint64)\0"
    "x_rawCommandReply(QxFtp*,int,QString)\0"
    "x_commandStarted(QxFtp*,int)\0"
    "x_commandFinished(QxFtp*,int,bool)\0"
    "x_done(QxFtp*,bool)\0old_stateChanged(int)\0"
    "old_listInfo(QUrlInfo)\0old_readyRead()\0"
    "old_dataTransferProgress(qint64,qint64)\0"
    "old_rawCommandReply(int,QString)\0"
    "old_commandStarted(int)\0"
    "old_commandFinished(int,bool)\0"
    "old_done(bool)\0"
};

const QMetaObject QxFtp::staticMetaObject = {
    { &QFtp::staticMetaObject, qt_meta_stringdata_QxFtp,
      qt_meta_data_QxFtp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QxFtp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QxFtp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QxFtp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QxFtp))
        return static_cast<void*>(const_cast< QxFtp*>(this));
    return QFtp::qt_metacast(_clname);
}

int QxFtp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFtp::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: x_stateChanged((*reinterpret_cast< QxFtp*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: x_listInfo((*reinterpret_cast< QxFtp*(*)>(_a[1])),(*reinterpret_cast< const QUrlInfo(*)>(_a[2]))); break;
        case 2: x_readyRead((*reinterpret_cast< QxFtp*(*)>(_a[1]))); break;
        case 3: x_dataTransferProgress((*reinterpret_cast< QxFtp*(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        case 4: x_rawCommandReply((*reinterpret_cast< QxFtp*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 5: x_commandStarted((*reinterpret_cast< QxFtp*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: x_commandFinished((*reinterpret_cast< QxFtp*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 7: x_done((*reinterpret_cast< QxFtp*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: old_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: old_listInfo((*reinterpret_cast< const QUrlInfo(*)>(_a[1]))); break;
        case 10: old_readyRead(); break;
        case 11: old_dataTransferProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 12: old_rawCommandReply((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 13: old_commandStarted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: old_commandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 15: old_done((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void QxFtp::x_stateChanged(QxFtp * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QxFtp::x_listInfo(QxFtp * _t1, const QUrlInfo & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QxFtp::x_readyRead(QxFtp * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QxFtp::x_dataTransferProgress(QxFtp * _t1, qint64 _t2, qint64 _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QxFtp::x_rawCommandReply(QxFtp * _t1, int _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QxFtp::x_commandStarted(QxFtp * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QxFtp::x_commandFinished(QxFtp * _t1, int _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QxFtp::x_done(QxFtp * _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
