/****************************************************************************
** Meta object code from reading C++ file 'Hitman5_External.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Hitman5_External.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Hitman5_External.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Hitman5_External_t {
    QByteArrayData data[9];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Hitman5_External_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Hitman5_External_t qt_meta_stringdata_Hitman5_External = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Hitman5_External"
QT_MOC_LITERAL(1, 17, 20), // "onHealthApplyClicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 27), // "onR_PistolAmmo_ApplyClicked"
QT_MOC_LITERAL(4, 67, 27), // "onL_PistolAmmo_ApplyClicked"
QT_MOC_LITERAL(5, 95, 25), // "onX_Posation_ApplyClicked"
QT_MOC_LITERAL(6, 121, 25), // "onY_Posation_ApplyClicked"
QT_MOC_LITERAL(7, 147, 25), // "onZ_Posation_ApplyClicked"
QT_MOC_LITERAL(8, 173, 17) // "onCheckBoxChanged"

    },
    "Hitman5_External\0onHealthApplyClicked\0"
    "\0onR_PistolAmmo_ApplyClicked\0"
    "onL_PistolAmmo_ApplyClicked\0"
    "onX_Posation_ApplyClicked\0"
    "onY_Posation_ApplyClicked\0"
    "onZ_Posation_ApplyClicked\0onCheckBoxChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hitman5_External[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Hitman5_External::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Hitman5_External *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onHealthApplyClicked(); break;
        case 1: _t->onR_PistolAmmo_ApplyClicked(); break;
        case 2: _t->onL_PistolAmmo_ApplyClicked(); break;
        case 3: _t->onX_Posation_ApplyClicked(); break;
        case 4: _t->onY_Posation_ApplyClicked(); break;
        case 5: _t->onZ_Posation_ApplyClicked(); break;
        case 6: _t->onCheckBoxChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Hitman5_External::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Hitman5_External.data,
    qt_meta_data_Hitman5_External,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Hitman5_External::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hitman5_External::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Hitman5_External.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Hitman5_External::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
