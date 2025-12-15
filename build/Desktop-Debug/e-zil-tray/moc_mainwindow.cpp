/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../e-zil-tray/mainwindow.h"
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
    char stringdata0[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "WidgetClosed"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "zilKontrol"
QT_MOC_LITERAL(4, 36, 4), // "init"
QT_MOC_LITERAL(5, 41, 13), // "iconActivated"
QT_MOC_LITERAL(6, 55, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(7, 89, 5), // "gizle"
QT_MOC_LITERAL(8, 95, 10), // "widgetShow"
QT_MOC_LITERAL(9, 106, 11), // "widgetAktif"
QT_MOC_LITERAL(10, 118, 11), // "resetStatus"
QT_MOC_LITERAL(11, 130, 10), // "torenMuzik"
QT_MOC_LITERAL(12, 141, 4), // "ders"
QT_MOC_LITERAL(13, 146, 12), // "ogrenciMuzik"
QT_MOC_LITERAL(14, 159, 13), // "ogretmenMuzik"
QT_MOC_LITERAL(15, 173, 10), // "cikisMuzik"
QT_MOC_LITERAL(16, 184, 17), // "yayinTenefusMuzik"
QT_MOC_LITERAL(17, 202, 14), // "yayinMolaMuzik"
QT_MOC_LITERAL(18, 217, 9), // "onemliGun"
QT_MOC_LITERAL(19, 227, 12), // "saniyeToSaat"
QT_MOC_LITERAL(20, 240, 6), // "_zaman"
QT_MOC_LITERAL(21, 247, 12) // "saatToSaniye"

    },
    "MainWindow\0WidgetClosed\0\0zilKontrol\0"
    "init\0iconActivated\0QSystemTrayIcon::ActivationReason\0"
    "gizle\0widgetShow\0widgetAktif\0resetStatus\0"
    "torenMuzik\0ders\0ogrenciMuzik\0ogretmenMuzik\0"
    "cikisMuzik\0yayinTenefusMuzik\0"
    "yayinMolaMuzik\0onemliGun\0saniyeToSaat\0"
    "_zaman\0saatToSaniye"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a /* Public */,
       3,    0,  100,    2, 0x0a /* Public */,
       4,    0,  101,    2, 0x0a /* Public */,
       5,    1,  102,    2, 0x0a /* Public */,
       7,    0,  105,    2, 0x0a /* Public */,
       8,    0,  106,    2, 0x0a /* Public */,
       9,    0,  107,    2, 0x0a /* Public */,
      10,    0,  108,    2, 0x0a /* Public */,
      11,    1,  109,    2, 0x0a /* Public */,
      13,    1,  112,    2, 0x0a /* Public */,
      14,    1,  115,    2, 0x0a /* Public */,
      15,    1,  118,    2, 0x0a /* Public */,
      16,    0,  121,    2, 0x0a /* Public */,
      17,    0,  122,    2, 0x0a /* Public */,
      18,    0,  123,    2, 0x0a /* Public */,
      19,    1,  124,    2, 0x0a /* Public */,
      21,    1,  127,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QTime, QMetaType::QString,   20,
    QMetaType::QString, QMetaType::QTime,   20,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->WidgetClosed(); break;
        case 1: _t->zilKontrol(); break;
        case 2: _t->init(); break;
        case 3: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 4: _t->gizle(); break;
        case 5: _t->widgetShow(); break;
        case 6: _t->widgetAktif(); break;
        case 7: _t->resetStatus(); break;
        case 8: _t->torenMuzik((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->ogrenciMuzik((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->ogretmenMuzik((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->cikisMuzik((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->yayinTenefusMuzik(); break;
        case 13: _t->yayinMolaMuzik(); break;
        case 14: _t->onemliGun(); break;
        case 15: { QTime _r = _t->saniyeToSaat((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QTime*>(_a[0]) = std::move(_r); }  break;
        case 16: { QString _r = _t->saatToSaniye((*reinterpret_cast< QTime(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
