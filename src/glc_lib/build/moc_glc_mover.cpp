/****************************************************************************
** Meta object code from reading C++ file 'glc_mover.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../viewport/glc_mover.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glc_mover.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GLC_Mover_t {
    QByteArrayData data[3];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GLC_Mover_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GLC_Mover_t qt_meta_stringdata_GLC_Mover = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GLC_Mover"
QT_MOC_LITERAL(1, 10, 7), // "updated"
QT_MOC_LITERAL(2, 18, 0) // ""

    },
    "GLC_Mover\0updated\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GLC_Mover[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void GLC_Mover::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GLC_Mover *_t = static_cast<GLC_Mover *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updated(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GLC_Mover::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLC_Mover::updated)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GLC_Mover::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GLC_Mover.data,
      qt_meta_data_GLC_Mover,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GLC_Mover::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GLC_Mover::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GLC_Mover.stringdata0))
        return static_cast<void*>(const_cast< GLC_Mover*>(this));
    return QObject::qt_metacast(_clname);
}

int GLC_Mover::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void GLC_Mover::updated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
