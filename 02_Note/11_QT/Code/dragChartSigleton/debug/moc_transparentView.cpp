/****************************************************************************
** Meta object code from reading C++ file 'transparentView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../transparentView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transparentView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TransparentView_t {
    QByteArrayData data[5];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TransparentView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TransparentView_t qt_meta_stringdata_TransparentView = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TransparentView"
QT_MOC_LITERAL(1, 16, 16), // "sendMappingRange"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "bottom"
QT_MOC_LITERAL(4, 41, 3) // "top"

    },
    "TransparentView\0sendMappingRange\0\0"
    "bottom\0top"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TransparentView[] = {

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
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,

       0        // eod
};

void TransparentView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TransparentView *_t = static_cast<TransparentView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMappingRange((*reinterpret_cast< const double(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TransparentView::*_t)(const double , const double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TransparentView::sendMappingRange)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TransparentView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TransparentView.data,
      qt_meta_data_TransparentView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TransparentView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TransparentView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TransparentView.stringdata0))
        return static_cast<void*>(const_cast< TransparentView*>(this));
    return QWidget::qt_metacast(_clname);
}

int TransparentView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void TransparentView::sendMappingRange(const double _t1, const double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
