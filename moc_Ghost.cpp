/****************************************************************************
** Meta object code from reading C++ file 'Ghost.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "Ghost.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Ghost.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Ghost_t {
    QByteArrayData data[20];
    char stringdata0[299];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ghost_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ghost_t qt_meta_stringdata_Ghost = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Ghost"
QT_MOC_LITERAL(1, 6, 12), // "getDirection"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "targetX"
QT_MOC_LITERAL(4, 28, 7), // "targetY"
QT_MOC_LITERAL(5, 36, 16), // "getDirectionForX"
QT_MOC_LITERAL(6, 53, 16), // "getDirectionForY"
QT_MOC_LITERAL(7, 70, 25), // "getDirectionForBlockedWay"
QT_MOC_LITERAL(8, 96, 17), // "getChaseDirection"
QT_MOC_LITERAL(9, 114, 23), // "getFrightenedDirections"
QT_MOC_LITERAL(10, 138, 19), // "getScatterDirection"
QT_MOC_LITERAL(11, 158, 17), // "getEatenDirection"
QT_MOC_LITERAL(12, 176, 21), // "getOutOfCageDirection"
QT_MOC_LITERAL(13, 198, 17), // "leaveFrightenMode"
QT_MOC_LITERAL(14, 216, 17), // "enterFrightenMode"
QT_MOC_LITERAL(15, 234, 16), // "leaveScatterMode"
QT_MOC_LITERAL(16, 251, 16), // "enterScatterMode"
QT_MOC_LITERAL(17, 268, 14), // "enterEatenMode"
QT_MOC_LITERAL(18, 283, 8), // "isInCage"
QT_MOC_LITERAL(19, 292, 6) // "update"

    },
    "Ghost\0getDirection\0\0targetX\0targetY\0"
    "getDirectionForX\0getDirectionForY\0"
    "getDirectionForBlockedWay\0getChaseDirection\0"
    "getFrightenedDirections\0getScatterDirection\0"
    "getEatenDirection\0getOutOfCageDirection\0"
    "leaveFrightenMode\0enterFrightenMode\0"
    "leaveScatterMode\0enterScatterMode\0"
    "enterEatenMode\0isInCage\0update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ghost[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   94,    2, 0x0a /* Public */,
       5,    2,   99,    2, 0x0a /* Public */,
       6,    2,  104,    2, 0x0a /* Public */,
       7,    0,  109,    2, 0x0a /* Public */,
       8,    0,  110,    2, 0x0a /* Public */,
       9,    0,  111,    2, 0x0a /* Public */,
      10,    0,  112,    2, 0x0a /* Public */,
      11,    0,  113,    2, 0x0a /* Public */,
      12,    0,  114,    2, 0x0a /* Public */,
      13,    0,  115,    2, 0x0a /* Public */,
      14,    0,  116,    2, 0x0a /* Public */,
      15,    0,  117,    2, 0x0a /* Public */,
      16,    0,  118,    2, 0x0a /* Public */,
      17,    0,  119,    2, 0x0a /* Public */,
      18,    0,  120,    2, 0x0a /* Public */,
      19,    0,  121,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void Ghost::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Ghost *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->getDirection((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->getDirectionForX((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->getDirectionForY((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->getDirectionForBlockedWay(); break;
        case 4: _t->getChaseDirection(); break;
        case 5: _t->getFrightenedDirections(); break;
        case 6: _t->getScatterDirection(); break;
        case 7: _t->getEatenDirection(); break;
        case 8: _t->getOutOfCageDirection(); break;
        case 9: _t->leaveFrightenMode(); break;
        case 10: _t->enterFrightenMode(); break;
        case 11: _t->leaveScatterMode(); break;
        case 12: _t->enterScatterMode(); break;
        case 13: _t->enterEatenMode(); break;
        case 14: { bool _r = _t->isInCage();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->update(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Ghost::staticMetaObject = { {
    QMetaObject::SuperData::link<Entity::staticMetaObject>(),
    qt_meta_stringdata_Ghost.data,
    qt_meta_data_Ghost,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Ghost::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ghost::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Ghost.stringdata0))
        return static_cast<void*>(this);
    return Entity::qt_metacast(_clname);
}

int Ghost::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Entity::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
