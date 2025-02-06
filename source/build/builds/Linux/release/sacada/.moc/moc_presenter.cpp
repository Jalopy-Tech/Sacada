/****************************************************************************
** Meta object code from reading C++ file 'presenter.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../presenters/presenter.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'presenter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN9PresenterE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN9PresenterE = QtMocHelpers::stringData(
    "Presenter",
    "findArtFinished",
    "",
    "handleFindArtStarted",
    "handleFindArtReadReady",
    "handleFindArtErrorOccurred",
    "QProcess::ProcessError",
    "error",
    "handleFindArtFinished",
    "exitCode",
    "QProcess::ExitStatus",
    "exitStatus",
    "handleFindArtProgressed",
    "progress",
    "progressText",
    "handleUpdateArtDetails",
    "albumArtist",
    "album",
    "size",
    "handleSetFinalPath",
    "finalPath",
    "findArt",
    "setLocations",
    "saveArt",
    "QList<bool>",
    "isApprovedList",
    "openTempArt",
    "openFinalArt"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN9PresenterE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   93,    2, 0x0a,    2 /* Public */,
       4,    0,   94,    2, 0x0a,    3 /* Public */,
       5,    1,   95,    2, 0x0a,    4 /* Public */,
       8,    2,   98,    2, 0x0a,    6 /* Public */,
      12,    2,  103,    2, 0x0a,    9 /* Public */,
      15,    3,  108,    2, 0x0a,   12 /* Public */,
      19,    1,  115,    2, 0x0a,   16 /* Public */,
      21,    0,  118,    2, 0x0a,   18 /* Public */,
      22,    0,  119,    2, 0x0a,   19 /* Public */,
      23,    1,  120,    2, 0x0a,   20 /* Public */,
      26,    0,  123,    2, 0x0a,   22 /* Public */,
      27,    0,  124,    2, 0x0a,   23 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 10,    9,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,   16,   17,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Presenter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN9PresenterE.offsetsAndSizes,
    qt_meta_data_ZN9PresenterE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN9PresenterE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Presenter, std::true_type>,
        // method 'findArtFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleFindArtStarted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleFindArtReadReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleFindArtErrorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QProcess::ProcessError, std::false_type>,
        // method 'handleFindArtFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QProcess::ExitStatus, std::false_type>,
        // method 'handleFindArtProgressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'handleUpdateArtDetails'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handleSetFinalPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'findArt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setLocations'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveArt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<bool> &, std::false_type>,
        // method 'openTempArt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openFinalArt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Presenter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Presenter *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->findArtFinished(); break;
        case 1: _t->handleFindArtStarted(); break;
        case 2: _t->handleFindArtReadReady(); break;
        case 3: _t->handleFindArtErrorOccurred((*reinterpret_cast< std::add_pointer_t<QProcess::ProcessError>>(_a[1]))); break;
        case 4: _t->handleFindArtFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QProcess::ExitStatus>>(_a[2]))); break;
        case 5: _t->handleFindArtProgressed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 6: _t->handleUpdateArtDetails((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->handleSetFinalPath((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->findArt(); break;
        case 9: _t->setLocations(); break;
        case 10: _t->saveArt((*reinterpret_cast< std::add_pointer_t<QList<bool>>>(_a[1]))); break;
        case 11: _t->openTempArt(); break;
        case 12: _t->openFinalArt(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<bool> >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (Presenter::*)();
            if (_q_method_type _q_method = &Presenter::findArtFinished; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Presenter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Presenter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN9PresenterE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Presenter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Presenter::findArtFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
