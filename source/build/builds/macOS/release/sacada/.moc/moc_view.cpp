/****************************************************************************
** Meta object code from reading C++ file 'view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../source/views/view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_View_t {
    const uint offsetsAndSize[32];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_View_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_View_t qt_meta_stringdata_View = {
    {
QT_MOC_LITERAL(0, 4), // "View"
QT_MOC_LITERAL(5, 17), // "artDetailsUpdated"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 11), // "albumArtist"
QT_MOC_LITERAL(36, 5), // "album"
QT_MOC_LITERAL(42, 4), // "size"
QT_MOC_LITERAL(47, 16), // "finalPathUpdated"
QT_MOC_LITERAL(64, 9), // "finalPath"
QT_MOC_LITERAL(74, 16), // "saveArtRequested"
QT_MOC_LITERAL(91, 11), // "QList<bool>"
QT_MOC_LITERAL(103, 14), // "isApprovedList"
QT_MOC_LITERAL(118, 20), // "openTempArtRequested"
QT_MOC_LITERAL(139, 21), // "openFinalArtRequested"
QT_MOC_LITERAL(161, 21), // "setLocationsRequested"
QT_MOC_LITERAL(183, 16), // "findArtRequested"
QT_MOC_LITERAL(200, 15) // "findArtFinished"

    },
    "View\0artDetailsUpdated\0\0albumArtist\0"
    "album\0size\0finalPathUpdated\0finalPath\0"
    "saveArtRequested\0QList<bool>\0"
    "isApprovedList\0openTempArtRequested\0"
    "openFinalArtRequested\0setLocationsRequested\0"
    "findArtRequested\0findArtFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   62,    2, 0x06,    1 /* Public */,
       6,    1,   69,    2, 0x06,    5 /* Public */,
       8,    1,   72,    2, 0x06,    7 /* Public */,
      11,    0,   75,    2, 0x06,    9 /* Public */,
      12,    0,   76,    2, 0x06,   10 /* Public */,
      13,    0,   77,    2, 0x06,   11 /* Public */,
      14,    0,   78,    2, 0x06,   12 /* Public */,
      15,    0,   79,    2, 0x06,   13 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    4,    5,
    QMetaType::Bool, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<View *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->artDetailsUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: { bool _r = _t->finalPathUpdated((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->saveArtRequested((*reinterpret_cast< const QList<bool>(*)>(_a[1]))); break;
        case 3: _t->openTempArtRequested(); break;
        case 4: _t->openFinalArtRequested(); break;
        case 5: _t->setLocationsRequested(); break;
        case 6: _t->findArtRequested(); break;
        case 7: _t->findArtFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<bool> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (View::*)(const QString & , const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&View::artDetailsUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = bool (View::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&View::finalPathUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (View::*)(const QList<bool> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&View::saveArtRequested)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (View::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&View::openTempArtRequested)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (View::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&View::openFinalArtRequested)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (View::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&View::setLocationsRequested)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (View::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&View::findArtRequested)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (View::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&View::findArtFinished)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject View::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_View.offsetsAndSize,
    qt_meta_data_View,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_View_t
, QtPrivate::TypeAndForceComplete<View, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QList<bool> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_View.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void View::artDetailsUpdated(const QString & _t1, const QString & _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
bool View::finalPathUpdated(const QString & _t1)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
void View::saveArtRequested(const QList<bool> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void View::openTempArtRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void View::openFinalArtRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void View::setLocationsRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void View::findArtRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void View::findArtFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
