/****************************************************************************
** Meta object code from reading C++ file 'query.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ElectronicNotes/include/query.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'query.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Query_t {
    QByteArrayData data[12];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Query_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Query_t qt_meta_stringdata_Query = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Query"
QT_MOC_LITERAL(1, 6, 20), // "PushButtonAddClicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 17), // "ComboBoxActivated"
QT_MOC_LITERAL(4, 46, 5), // "index"
QT_MOC_LITERAL(5, 52, 22), // "TableWidgetCellClicked"
QT_MOC_LITERAL(6, 75, 3), // "row"
QT_MOC_LITERAL(7, 79, 6), // "column"
QT_MOC_LITERAL(8, 86, 23), // "PushButtonUpdateClicked"
QT_MOC_LITERAL(9, 110, 20), // "PushButtonPreClicked"
QT_MOC_LITERAL(10, 131, 21), // "PushButtonNextClicked"
QT_MOC_LITERAL(11, 153, 22) // "PushButtonQueryClicked"

    },
    "Query\0PushButtonAddClicked\0\0"
    "ComboBoxActivated\0index\0TableWidgetCellClicked\0"
    "row\0column\0PushButtonUpdateClicked\0"
    "PushButtonPreClicked\0PushButtonNextClicked\0"
    "PushButtonQueryClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Query[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    1,   50,    2, 0x08 /* Private */,
       5,    2,   53,    2, 0x08 /* Private */,
       8,    0,   58,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,
      10,    0,   60,    2, 0x08 /* Private */,
      11,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Query::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Query *_t = static_cast<Query *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PushButtonAddClicked(); break;
        case 1: _t->ComboBoxActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->TableWidgetCellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->PushButtonUpdateClicked(); break;
        case 4: _t->PushButtonPreClicked(); break;
        case 5: _t->PushButtonNextClicked(); break;
        case 6: _t->PushButtonQueryClicked(); break;
        default: ;
        }
    }
}

const QMetaObject Query::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Query.data,
      qt_meta_data_Query,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Query::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Query::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Query.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Query::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
