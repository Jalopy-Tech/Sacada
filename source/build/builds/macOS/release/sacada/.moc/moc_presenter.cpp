/****************************************************************************
** Meta object code from reading C++ file 'presenter.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../source/presenters/presenter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'presenter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Presenter_t {
    const uint offsetsAndSize[56];
    char stringdata0[392];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Presenter_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Presenter_t qt_meta_stringdata_Presenter = {
    {
QT_MOC_LITERAL(0, 9), // "Presenter"
QT_MOC_LITERAL(10, 15), // "findArtFinished"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 20), // "handleFindArtStarted"
QT_MOC_LITERAL(48, 22), // "handleFindArtReadReady"
QT_MOC_LITERAL(71, 26), // "handleFindArtErrorOccurred"
QT_MOC_LITERAL(98, 22), // "QProcess::ProcessError"
QT_MOC_LITERAL(121, 5), // "error"
QT_MOC_LITERAL(127, 21), // "handleFindArtFinished"
QT_MOC_LITERAL(149, 8), // "exitCode"
QT_MOC_LITERAL(158, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(179, 10), // "exitStatus"
QT_MOC_LITERAL(190, 23), // "handleFindArtProgressed"
QT_MOC_LITERAL(214, 8), // "progress"
QT_MOC_LITERAL(223, 12), // "progressText"
QT_MOC_LITERAL(236, 22), // "handleUpdateArtDetails"
QT_MOC_LITERAL(259, 11), // "albumArtist"
QT_MOC_LITERAL(271, 5), // "album"
QT_MOC_LITERAL(277, 4), // "size"
QT_MOC_LITERAL(282, 18), // "handleSetFinalPath"
QT_MOC_LITERAL(301, 9), // "finalPath"
QT_MOC_LITERAL(311, 7), // "findArt"
QT_MOC_LITERAL(319, 12), // "setLocations"
QT_MOC_LITERAL(332, 7), // "saveArt"
QT_MOC_LITERAL(340, 11), // "QList<bool>"
QT_MOC_LITERAL(352, 14), // "isApprovedList"
QT_MOC_LITERAL(367, 11), // "openTempArt"
QT_MOC_LITERAL(379, 12) // "openFinalArt"

    },
    "Presenter\0findArtFinished\0\0"
    "handleFindArtStarted\0handleFindArtReadReady\0"
    "handleFindArtErrorOccurred\0"
    "QProcess::ProcessError\0error\0"
    "handleFindArtFinished\0exitCode\0"
    "QProcess::ExitStatus\0exitStatus\0"
    "handleFindArtProgressed\0progress\0"
    "progressText\0handleUpdateArtDetails\0"
    "albumArtist\0album\0size\0handleSetFinalPath\0"
    "finalPath\0findArt\0setLocations\0saveArt\0"
    "QList<bool>\0isApprovedList\0openTempArt\0"
    "openFinalArt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Presenter[] = {

 // content:
      10,       // revision
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

void Presenter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Presenter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->findArtFinished(); break;
        case 1: _t->handleFindArtStarted(); break;
        case 2: _t->handleFindArtReadReady(); break;
        case 3: _t->handleFindArtErrorOccurred((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 4: _t->handleFindArtFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 5: _t->handleFindArtProgressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->handleUpdateArtDetails((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->handleSetFinalPath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->findArt(); break;
        case 9: _t->setLocations(); break;
        case 10: _t->saveArt((*reinterpret_cast< const QList<bool>(*)>(_a[1]))); break;
        case 11: _t->openTempArt(); break;
        case 12: _t->openFinalArt(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Presenter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Presenter::findArtFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Presenter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Presenter.offsetsAndSize,
    qt_meta_data_Presenter,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Presenter_t
, QtPrivate::TypeAndForceComplete<Presenter, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QProcess::ProcessError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QProcess::ExitStatus, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QList<bool> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Presenter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Presenter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Presenter.stringdata0))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
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
QT_END_MOC_NAMESPACE
