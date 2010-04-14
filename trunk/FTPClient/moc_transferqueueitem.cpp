/****************************************************************************
** Meta object code from reading C++ file 'transferqueueitem.h'
**
** Created
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "transferqueueitem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transferqueueitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TransferQueueItem[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   19,   18,   18, 0x08,
      58,   43,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TransferQueueItem[] = {
    "TransferQueueItem\0\0amoutn\0setComplete(int)\0"
    ",current,total\0updateProgress(QxFtp*,qint64,qint64)\0"
};

const QMetaObject TransferQueueItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TransferQueueItem,
      qt_meta_data_TransferQueueItem, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TransferQueueItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TransferQueueItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TransferQueueItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TransferQueueItem))
        return static_cast<void*>(const_cast< TransferQueueItem*>(this));
    return QObject::qt_metacast(_clname);
}

int TransferQueueItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setComplete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: updateProgress((*reinterpret_cast< QxFtp*(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
