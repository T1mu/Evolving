/****************************************************************************
** Meta object code from reading C++ file 'calibration_test1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../calibration_test1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calibration_test1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_calibration_test1_t {
    QByteArrayData data[8];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_calibration_test1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_calibration_test1_t qt_meta_stringdata_calibration_test1 = {
    {
QT_MOC_LITERAL(0, 0, 17), // "calibration_test1"
QT_MOC_LITERAL(1, 18, 13), // "center_signal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "double*"
QT_MOC_LITERAL(4, 41, 14), // "ProcessPicture"
QT_MOC_LITERAL(5, 56, 9), // "Time_show"
QT_MOC_LITERAL(6, 66, 17), // "dealcenter_signal"
QT_MOC_LITERAL(7, 84, 4) // "para"

    },
    "calibration_test1\0center_signal\0\0"
    "double*\0ProcessPicture\0Time_show\0"
    "dealcenter_signal\0para"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calibration_test1[] = {

 // content:
       7,       // revision
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
       4,    1,   37,    2, 0x08 /* Private */,
       5,    0,   40,    2, 0x08 /* Private */,
       6,    1,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    7,

       0        // eod
};

void calibration_test1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        calibration_test1 *_t = static_cast<calibration_test1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->center_signal((*reinterpret_cast< double*(*)>(_a[1]))); break;
        case 1: _t->ProcessPicture((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->Time_show(); break;
        case 3: _t->dealcenter_signal((*reinterpret_cast< double*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (calibration_test1::*_t)(double * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&calibration_test1::center_signal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject calibration_test1::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_calibration_test1.data,
      qt_meta_data_calibration_test1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *calibration_test1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calibration_test1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_calibration_test1.stringdata0))
        return static_cast<void*>(const_cast< calibration_test1*>(this));
    return QWidget::qt_metacast(_clname);
}

int calibration_test1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void calibration_test1::center_signal(double * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
