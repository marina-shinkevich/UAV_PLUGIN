/****************************************************************************
** Meta object code from reading C++ file 'dataread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "dataread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataRead_t {
    QByteArrayData data[25];
    char stringdata0[369];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataRead_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataRead_t qt_meta_stringdata_DataRead = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DataRead"
QT_MOC_LITERAL(1, 9, 24), // "aircraftSelectionChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 17), // "refreshConnection"
QT_MOC_LITERAL(4, 53, 12), // "httpFinished"
QT_MOC_LITERAL(5, 66, 13), // "httpReadyRead"
QT_MOC_LITERAL(6, 80, 26), // "slotAuthenticationRequired"
QT_MOC_LITERAL(7, 107, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 122, 15), // "QAuthenticator*"
QT_MOC_LITERAL(9, 138, 13), // "authenticator"
QT_MOC_LITERAL(10, 152, 19), // "onClickReportTarget"
QT_MOC_LITERAL(11, 172, 17), // "openReportMsgView"
QT_MOC_LITERAL(12, 190, 18), // "closeReportMsgView"
QT_MOC_LITERAL(13, 209, 15), // "updateVariables"
QT_MOC_LITERAL(14, 225, 4), // "name"
QT_MOC_LITERAL(15, 230, 5), // "state"
QT_MOC_LITERAL(16, 236, 20), // "setAircraftSelection"
QT_MOC_LITERAL(17, 257, 8), // "aircraft"
QT_MOC_LITERAL(18, 266, 13), // "currentReport"
QT_MOC_LITERAL(19, 280, 14), // "MandalaValues*"
QT_MOC_LITERAL(20, 295, 10), // "UVH_VT_170"
QT_MOC_LITERAL(21, 306, 7), // "VT_25V1"
QT_MOC_LITERAL(22, 314, 16), // "refreshInterface"
QT_MOC_LITERAL(23, 331, 17), // "aircraftSelection"
QT_MOC_LITERAL(24, 349, 19) // "currentAircraftName"

    },
    "DataRead\0aircraftSelectionChanged\0\0"
    "refreshConnection\0httpFinished\0"
    "httpReadyRead\0slotAuthenticationRequired\0"
    "QNetworkReply*\0QAuthenticator*\0"
    "authenticator\0onClickReportTarget\0"
    "openReportMsgView\0closeReportMsgView\0"
    "updateVariables\0name\0state\0"
    "setAircraftSelection\0aircraft\0"
    "currentReport\0MandalaValues*\0UVH_VT_170\0"
    "VT_25V1\0refreshInterface\0aircraftSelection\0"
    "currentAircraftName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataRead[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       2,  108, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    2,   88,    2, 0x0a /* Public */,
      10,    0,   93,    2, 0x0a /* Public */,
      11,    0,   94,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x0a /* Public */,
      13,    2,   96,    2, 0x0a /* Public */,
      16,    1,  101,    2, 0x0a /* Public */,
      18,    0,  104,    2, 0x0a /* Public */,
      20,    0,  105,    2, 0x0a /* Public */,
      21,    0,  106,    2, 0x0a /* Public */,
      22,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 8,    2,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,   14,   15,
    QMetaType::Void, QMetaType::Int,   17,
    0x80000000 | 19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      23, QMetaType::Int, 0x00495103,
      24, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       0,

       0        // eod
};

void DataRead::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataRead *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->aircraftSelectionChanged(); break;
        case 1: _t->refreshConnection(); break;
        case 2: _t->httpFinished(); break;
        case 3: _t->httpReadyRead(); break;
        case 4: _t->slotAuthenticationRequired((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        case 5: _t->onClickReportTarget(); break;
        case 6: _t->openReportMsgView(); break;
        case 7: _t->closeReportMsgView(); break;
        case 8: _t->updateVariables((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 9: _t->setAircraftSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: { MandalaValues* _r = _t->currentReport();
            if (_a[0]) *reinterpret_cast< MandalaValues**>(_a[0]) = std::move(_r); }  break;
        case 11: _t->UVH_VT_170(); break;
        case 12: _t->VT_25V1(); break;
        case 13: _t->refreshInterface(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataRead::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataRead::aircraftSelectionChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DataRead *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->aircraftSelection(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->currentAircraftName(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DataRead *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAircraftSelection(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject DataRead::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DataRead.data,
    qt_meta_data_DataRead,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataRead::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataRead::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataRead.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataRead::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DataRead::aircraftSelectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
