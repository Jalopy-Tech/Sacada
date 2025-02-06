/****************************************************************************
** Meta object code from reading C++ file 'artwizard.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../source/views/artwizard/artwizard.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'artwizard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ArtWizard_t {
    const uint offsetsAndSize[38];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ArtWizard_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ArtWizard_t qt_meta_stringdata_ArtWizard = {
    {
QT_MOC_LITERAL(0, 9), // "ArtWizard"
QT_MOC_LITERAL(10, 17), // "artDetailsUpdated"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 11), // "albumArtist"
QT_MOC_LITERAL(41, 5), // "album"
QT_MOC_LITERAL(47, 4), // "size"
QT_MOC_LITERAL(52, 16), // "finalPathUpdated"
QT_MOC_LITERAL(69, 9), // "finalPath"
QT_MOC_LITERAL(79, 16), // "findArtRequested"
QT_MOC_LITERAL(96, 16), // "saveArtRequested"
QT_MOC_LITERAL(113, 11), // "QList<bool>"
QT_MOC_LITERAL(125, 14), // "isApprovedList"
QT_MOC_LITERAL(140, 20), // "openTempArtRequested"
QT_MOC_LITERAL(161, 21), // "openFinalArtRequested"
QT_MOC_LITERAL(183, 21), // "setLocationsRequested"
QT_MOC_LITERAL(205, 19), // "toggleShowOrHideLog"
QT_MOC_LITERAL(225, 17), // "handlePageChanged"
QT_MOC_LITERAL(243, 5), // "newID"
QT_MOC_LITERAL(249, 4) // "help"

    },
    "ArtWizard\0artDetailsUpdated\0\0albumArtist\0"
    "album\0size\0finalPathUpdated\0finalPath\0"
    "findArtRequested\0saveArtRequested\0"
    "QList<bool>\0isApprovedList\0"
    "openTempArtRequested\0openFinalArtRequested\0"
    "setLocationsRequested\0toggleShowOrHideLog\0"
    "handlePageChanged\0newID\0help"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArtWizard[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   74,    2, 0x06,    1 /* Public */,
       6,    1,   81,    2, 0x06,    5 /* Public */,
       8,    0,   84,    2, 0x06,    7 /* Public */,
       9,    1,   85,    2, 0x06,    8 /* Public */,
      12,    0,   88,    2, 0x06,   10 /* Public */,
      13,    0,   89,    2, 0x06,   11 /* Public */,
      14,    0,   90,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    0,   91,    2, 0x0a,   13 /* Public */,
      16,    1,   92,    2, 0x08,   14 /* Private */,
      18,    0,   95,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    4,    5,
    QMetaType::Bool, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,

       0        // eod
};

void ArtWizard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ArtWizard *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->artDetailsUpdated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->finalPathUpdated((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->findArtRequested(); break;
        case 3: _t->saveArtRequested((*reinterpret_cast< const QList<bool>(*)>(_a[1]))); break;
        case 4: _t->openTempArtRequested(); break;
        case 5: _t->openFinalArtRequested(); break;
        case 6: _t->setLocationsRequested(); break;
        case 7: _t->toggleShowOrHideLog(); break;
        case 8: _t->handlePageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->help(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
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
            using _t = bool (ArtWizard::*)(const QString & , const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArtWizard::artDetailsUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = bool (ArtWizard::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArtWizard::finalPathUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ArtWizard::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArtWizard::findArtRequested)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ArtWizard::*)(const QList<bool> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArtWizard::saveArtRequested)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ArtWizard::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArtWizard::openTempArtRequested)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ArtWizard::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArtWizard::openFinalArtRequested)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ArtWizard::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArtWizard::setLocationsRequested)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject ArtWizard::staticMetaObject = { {
    QMetaObject::SuperData::link<QWizard::staticMetaObject>(),
    qt_meta_stringdata_ArtWizard.offsetsAndSize,
    qt_meta_data_ArtWizard,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ArtWizard_t
, QtPrivate::TypeAndForceComplete<ArtWizard, std::true_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QList<bool> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ArtWizard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArtWizard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ArtWizard.stringdata0))
        return static_cast<void*>(this);
    return QWizard::qt_metacast(_clname);
}

int ArtWizard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizard::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
bool ArtWizard::artDetailsUpdated(const QString & _t1, const QString & _t2, int _t3)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
bool ArtWizard::finalPathUpdated(const QString & _t1)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
void ArtWizard::findArtRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ArtWizard::saveArtRequested(const QList<bool> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ArtWizard::openTempArtRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ArtWizard::openFinalArtRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ArtWizard::setLocationsRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
