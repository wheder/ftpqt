/****************************************************************************
** Meta object code from reading C++ file 'panel.h'
**
** Created
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "panel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Panel[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,    7,    6,    6, 0x05,
      32,    6,    6,    6, 0x05,
      51,   49,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      99,    6,    6,    6, 0x08,
     125,    6,    6,    6, 0x08,
     151,    6,    6,    6, 0x08,
     177,    6,    6,    6, 0x08,
     210,  198,    6,    6, 0x08,
     263,  198,    6,    6, 0x08,
     322,  318,    6,    6, 0x08,
     341,    6,    6,    6, 0x08,
     371,  364,    6,    6, 0x08,
     418,  415,    6,    6, 0x08,
     446,  364,    6,    6, 0x08,
     477,  364,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Panel[] = {
    "Panel\0\0conn\0canTransfer(QxFtp*)\0"
    "canTransferNow()\0i\0"
    "newTransferQueueItemCreated(TransferQueueItem*)\0"
    "on_uploadButton_clicked()\0"
    "on_renameButton_clicked()\0"
    "on_deleteButton_clicked()\0"
    "on_cdUpFTP_clicked()\0item,column\0"
    "on_treeWidgetFTP_itemActivated(QTreeWidgetItem*,int)\0"
    "on_treeWidgetLocal_itemActivated(QTreeWidgetItem*,int)\0"
    "pwd\0changePwd(QString)\0on_cdUpLocal_clicked()\0"
    ",error\0directoryStructureOnFtpCreated(QxFtp*,bool)\0"
    ",a\0startTransfers(QxFtp*,bool)\0"
    "filesOnFTPDeleted(QxFtp*,bool)\0"
    "dirsOnFTPDeleted(QxFtp*,bool)\0"
};

const QMetaObject Panel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Panel,
      qt_meta_data_Panel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Panel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Panel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Panel))
        return static_cast<void*>(const_cast< Panel*>(this));
    return QWidget::qt_metacast(_clname);
}

int Panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: canTransfer((*reinterpret_cast< QxFtp*(*)>(_a[1]))); break;
        case 1: canTransferNow(); break;
        case 2: newTransferQueueItemCreated((*reinterpret_cast< TransferQueueItem*(*)>(_a[1]))); break;
        case 3: on_uploadButton_clicked(); break;
        case 4: on_renameButton_clicked(); break;
        case 5: on_deleteButton_clicked(); break;
        case 6: on_cdUpFTP_clicked(); break;
        case 7: on_treeWidgetFTP_itemActivated((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: on_treeWidgetLocal_itemActivated((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: changePwd((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: on_cdUpLocal_clicked(); break;
        case 11: directoryStructureOnFtpCreated((*reinterpret_cast< QxFtp*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 12: startTransfers((*reinterpret_cast< QxFtp*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: filesOnFTPDeleted((*reinterpret_cast< QxFtp*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 14: dirsOnFTPDeleted((*reinterpret_cast< QxFtp*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Panel::canTransfer(QxFtp * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Panel::canTransferNow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Panel::newTransferQueueItemCreated(TransferQueueItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
