/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "dosyaVarmi"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "dosya"
QT_MOC_LITERAL(4, 29, 8), // "SZSgizle"
QT_MOC_LITERAL(5, 38, 9), // "SZSgoster"
QT_MOC_LITERAL(6, 48, 5), // "about"
QT_MOC_LITERAL(7, 54, 10), // "widgetShow"
QT_MOC_LITERAL(8, 65, 13), // "onemliGunSlot"
QT_MOC_LITERAL(9, 79, 25), // "webTableCellDoubleClicked"
QT_MOC_LITERAL(10, 105, 4), // "iRow"
QT_MOC_LITERAL(11, 110, 7), // "iColumn"
QT_MOC_LITERAL(12, 118, 11), // "resetStatus"
QT_MOC_LITERAL(13, 130, 12), // "saniyeToSaat"
QT_MOC_LITERAL(14, 143, 6), // "_zaman"
QT_MOC_LITERAL(15, 150, 12), // "saatToSaniye"
QT_MOC_LITERAL(16, 163, 12), // "zamanHesapla"
QT_MOC_LITERAL(17, 176, 3), // "_sg"
QT_MOC_LITERAL(18, 180, 3), // "_sb"
QT_MOC_LITERAL(19, 184, 3), // "_sc"
QT_MOC_LITERAL(20, 188, 3), // "_st"
QT_MOC_LITERAL(21, 192, 13) // "baslamaZamani"

    },
    "MainWindow\0dosyaVarmi\0\0dosya\0SZSgizle\0"
    "SZSgoster\0about\0widgetShow\0onemliGunSlot\0"
    "webTableCellDoubleClicked\0iRow\0iColumn\0"
    "resetStatus\0saniyeToSaat\0_zaman\0"
    "saatToSaniye\0zamanHesapla\0_sg\0_sb\0_sc\0"
    "_st\0baslamaZamani"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a /* Public */,
       4,    0,   72,    2, 0x0a /* Public */,
       5,    0,   73,    2, 0x0a /* Public */,
       6,    0,   74,    2, 0x0a /* Public */,
       7,    0,   75,    2, 0x0a /* Public */,
       8,    0,   76,    2, 0x0a /* Public */,
       9,    2,   77,    2, 0x0a /* Public */,
      12,    0,   82,    2, 0x0a /* Public */,
      13,    1,   83,    2, 0x0a /* Public */,
      15,    1,   86,    2, 0x0a /* Public */,
      16,    5,   89,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::QTime, QMetaType::QString,   14,
    QMetaType::QString, QMetaType::QTime,   14,
    QMetaType::Void, QMetaType::QTime, QMetaType::QTime, QMetaType::QTime, QMetaType::QTime, QMetaType::QString,   17,   18,   19,   20,   21,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->dosyaVarmi((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->SZSgizle(); break;
        case 2: _t->SZSgoster(); break;
        case 3: _t->about(); break;
        case 4: _t->widgetShow(); break;
        case 5: _t->onemliGunSlot(); break;
        case 6: _t->webTableCellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->resetStatus(); break;
        case 8: { QTime _r = _t->saniyeToSaat((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTime*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->saatToSaniye((*reinterpret_cast< QTime(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->zamanHesapla((*reinterpret_cast< QTime(*)>(_a[1])),(*reinterpret_cast< QTime(*)>(_a[2])),(*reinterpret_cast< QTime(*)>(_a[3])),(*reinterpret_cast< QTime(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
