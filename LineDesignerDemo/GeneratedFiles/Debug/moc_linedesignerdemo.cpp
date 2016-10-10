/****************************************************************************
** Meta object code from reading C++ file 'linedesignerdemo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../linedesignerdemo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linedesignerdemo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LineDesignerDemo_t {
    QByteArrayData data[8];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LineDesignerDemo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LineDesignerDemo_t qt_meta_stringdata_LineDesignerDemo = {
    {
QT_MOC_LITERAL(0, 0, 16), // "LineDesignerDemo"
QT_MOC_LITERAL(1, 17, 13), // "buttonClicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 20), // "pushButton_3_Clicked"
QT_MOC_LITERAL(4, 53, 18), // "pushButton_Clicked"
QT_MOC_LITERAL(5, 72, 20), // "pushButton_4_Clicked"
QT_MOC_LITERAL(6, 93, 20), // "pushButton_2_Clicked"
QT_MOC_LITERAL(7, 114, 20) // "pushButton_5_Clicked"

    },
    "LineDesignerDemo\0buttonClicked\0\0"
    "pushButton_3_Clicked\0pushButton_Clicked\0"
    "pushButton_4_Clicked\0pushButton_2_Clicked\0"
    "pushButton_5_Clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineDesignerDemo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LineDesignerDemo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LineDesignerDemo *_t = static_cast<LineDesignerDemo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->buttonClicked(); break;
        case 1: _t->pushButton_3_Clicked(); break;
        case 2: _t->pushButton_Clicked(); break;
        case 3: _t->pushButton_4_Clicked(); break;
        case 4: _t->pushButton_2_Clicked(); break;
        case 5: _t->pushButton_5_Clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject LineDesignerDemo::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_LineDesignerDemo.data,
      qt_meta_data_LineDesignerDemo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LineDesignerDemo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LineDesignerDemo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LineDesignerDemo.stringdata0))
        return static_cast<void*>(const_cast< LineDesignerDemo*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int LineDesignerDemo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
