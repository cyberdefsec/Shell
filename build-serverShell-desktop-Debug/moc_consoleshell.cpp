/****************************************************************************
** Meta object code from reading C++ file 'consoleshell.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../serverShell/consoleshell.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'consoleshell.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConsoleShell_t {
    QByteArrayData data[10];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConsoleShell_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConsoleShell_t qt_meta_stringdata_ConsoleShell = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ConsoleShell"
QT_MOC_LITERAL(1, 13, 10), // "clientInfo"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "InfoClient"
QT_MOC_LITERAL(4, 36, 10), // "infoClient"
QT_MOC_LITERAL(5, 47, 16), // "setAddressServer"
QT_MOC_LITERAL(6, 64, 7), // "address"
QT_MOC_LITERAL(7, 72, 4), // "port"
QT_MOC_LITERAL(8, 77, 13), // "clientConnect"
QT_MOC_LITERAL(9, 91, 8) // "readData"

    },
    "ConsoleShell\0clientInfo\0\0InfoClient\0"
    "infoClient\0setAddressServer\0address\0"
    "port\0clientConnect\0readData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConsoleShell[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   37,    2, 0x0a /* Public */,
       8,    0,   42,    2, 0x08 /* Private */,
       9,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ConsoleShell::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConsoleShell *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clientInfo((*reinterpret_cast< const InfoClient(*)>(_a[1]))); break;
        case 1: _t->setAddressServer((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 2: _t->clientConnect(); break;
        case 3: _t->readData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConsoleShell::*)(const InfoClient & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConsoleShell::clientInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ConsoleShell::staticMetaObject = { {
    &QTextEdit::staticMetaObject,
    qt_meta_stringdata_ConsoleShell.data,
    qt_meta_data_ConsoleShell,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ConsoleShell::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConsoleShell::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConsoleShell.stringdata0))
        return static_cast<void*>(this);
    return QTextEdit::qt_metacast(_clname);
}

int ConsoleShell::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ConsoleShell::clientInfo(const InfoClient & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
