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
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,    7,    6,    6, 0x05,
      33,   31,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      81,    6,    6,    6, 0x08,
     107,    6,    6,    6, 0x08,
     133,    6,    6,    6, 0x08,
     159,    6,    6,    6, 0x08,
     192,  180,    6,    6, 0x08,
     245,  180,    6,    6, 0x08,
     304,  300,    6,    6, 0x08,
     323,    6,    6,    6, 0x08,
     352,  346,    6,    6, 0x08,
     391,  389,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Panel[] = {
    "Panel\0\0conn\0canTransfer(QFtp*)\0i\0"
    "newTransferQueueItemCreated(TransferQueueItem*)\0"
    "on_uploadButton_clicked()\0"
    "on_renameButton_clicked()\0"
    "on_deleteButton_clicked()\0"
    "on_cdUpFTP_clicked()\0item,column\0"
    "on_treeWidgetFTP_itemActivated(QTreeWidgetItem*,int)\0"
    "on_treeWidgetLocal_itemActivated(QTreeWidgetItem*,int)\0"
    "pwd\0changePwd(QString)\0on_cdUpLocal_clicked()\0"
    "error\0directoryStructureOnFtpCreated(bool)\0"
    "a\0startTransfers(bool)\0"
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
        case 0: canTransfer((*reinterpret_cast< QFtp*(*)>(_a[1]))); break;
        case 1: newTransferQueueItemCreated((*reinterpret_cast< TransferQueueItem*(*)>(_a[1]))); break;
        case 2: on_uploadButton_clicked(); break;
        case 3: on_renameButton_clicked(); break;
        case 4: on_deleteButton_clicked(); break;
        case 5: on_cdUpFTP_clicked(); break;
        case 6: on_treeWidgetFTP_itemActivated((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: on_treeWidgetLocal_itemActivated((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: changePwd((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: on_cdUpLocal_clicked(); break;
        case 10: directoryStructureOnFtpCreated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: startTransfers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Panel::canTransfer(QFtp * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Panel::newTransferQueueItemCreated(TransferQueueItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
