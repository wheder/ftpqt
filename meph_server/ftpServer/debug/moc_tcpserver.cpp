/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created: Thu 15. Apr 00:10:05 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tcpserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TCPServer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      28,   10,   10,   10, 0x08,
      50,   10,   10,   10, 0x08,
      61,   10,   10,   10, 0x08,
      76,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TCPServer[] = {
    "TCPServer\0\0displayRequest()\0"
    "dataSocketConnected()\0readData()\0"
    "disconnected()\0dataConnected()\0"
};

const QMetaObject TCPServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TCPServer,
      qt_meta_data_TCPServer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TCPServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TCPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TCPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TCPServer))
        return static_cast<void*>(const_cast< TCPServer*>(this));
    return QObject::qt_metacast(_clname);
}

int TCPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: displayRequest(); break;
        case 1: dataSocketConnected(); break;
        case 2: readData(); break;
        case 3: disconnected(); break;
        case 4: dataConnected(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
