/****************************************************************************
** Meta object code from reading C++ file 'mycalendar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mycalendar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mycalendar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyCalendar_t {
    const uint offsetsAndSize[18];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MyCalendar_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MyCalendar_t qt_meta_stringdata_MyCalendar = {
    {
QT_MOC_LITERAL(0, 10), // "MyCalendar"
QT_MOC_LITERAL(11, 21), // "scheduleButtonClicked"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 4), // "flag"
QT_MOC_LITERAL(39, 10), // "acceptHook"
QT_MOC_LITERAL(50, 3), // "num"
QT_MOC_LITERAL(54, 11), // "acceptClose"
QT_MOC_LITERAL(66, 12), // "acceptUnHook"
QT_MOC_LITERAL(79, 14) // "returnNowThing"

    },
    "MyCalendar\0scheduleButtonClicked\0\0"
    "flag\0acceptHook\0num\0acceptClose\0"
    "acceptUnHook\0returnNowThing"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyCalendar[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    0 /* Public */,
       4,    1,   47,    2, 0x06,    2 /* Public */,
       6,    1,   50,    2, 0x06,    4 /* Public */,
       7,    1,   53,    2, 0x06,    6 /* Public */,
       8,    0,   56,    2, 0x06,    8 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void MyCalendar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyCalendar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->scheduleButtonClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->acceptHook((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->acceptClose((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->acceptUnHook((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->returnNowThing(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyCalendar::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyCalendar::scheduleButtonClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyCalendar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyCalendar::acceptHook)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyCalendar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyCalendar::acceptClose)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyCalendar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyCalendar::acceptUnHook)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyCalendar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyCalendar::returnNowThing)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MyCalendar::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MyCalendar.offsetsAndSize,
    qt_meta_data_MyCalendar,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MyCalendar_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *MyCalendar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyCalendar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyCalendar.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MyCalendar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MyCalendar::scheduleButtonClicked(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyCalendar::acceptHook(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyCalendar::acceptClose(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyCalendar::acceptUnHook(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyCalendar::returnNowThing()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
