/****************************************************************************
** Meta object code from reading C++ file 'plugin_display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rviz_plugin_osvr/include/rviz_plugin_osvr/plugin_display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plugin_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_rviz_plugin_osvr__PluginDisplay_t {
    QByteArrayData data[9];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rviz_plugin_osvr__PluginDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rviz_plugin_osvr__PluginDisplay_t qt_meta_stringdata_rviz_plugin_osvr__PluginDisplay = {
    {
QT_MOC_LITERAL(0, 0, 31), // "rviz_plugin_osvr::PluginDisplay"
QT_MOC_LITERAL(1, 32, 19), // "onFullScreenChanged"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 14), // "onPubTfChanged"
QT_MOC_LITERAL(4, 68, 18), // "onFollowCamChanged"
QT_MOC_LITERAL(5, 87, 18), // "onPosOffsetChanged"
QT_MOC_LITERAL(6, 106, 17), // "onPosScaleChanged"
QT_MOC_LITERAL(7, 124, 19), // "onUseTrackerChanged"
QT_MOC_LITERAL(8, 144, 25) // "onResetOrientationChanged"

    },
    "rviz_plugin_osvr::PluginDisplay\0"
    "onFullScreenChanged\0\0onPubTfChanged\0"
    "onFollowCamChanged\0onPosOffsetChanged\0"
    "onPosScaleChanged\0onUseTrackerChanged\0"
    "onResetOrientationChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rviz_plugin_osvr__PluginDisplay[] = {

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
       1,    0,   49,    2, 0x09 /* Protected */,
       3,    0,   50,    2, 0x09 /* Protected */,
       4,    0,   51,    2, 0x09 /* Protected */,
       5,    0,   52,    2, 0x09 /* Protected */,
       6,    0,   53,    2, 0x09 /* Protected */,
       7,    0,   54,    2, 0x09 /* Protected */,
       8,    0,   55,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void rviz_plugin_osvr::PluginDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PluginDisplay *_t = static_cast<PluginDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onFullScreenChanged(); break;
        case 1: _t->onPubTfChanged(); break;
        case 2: _t->onFollowCamChanged(); break;
        case 3: _t->onPosOffsetChanged(); break;
        case 4: _t->onPosScaleChanged(); break;
        case 5: _t->onUseTrackerChanged(); break;
        case 6: _t->onResetOrientationChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject rviz_plugin_osvr::PluginDisplay::staticMetaObject = {
    { &rviz::Display::staticMetaObject, qt_meta_stringdata_rviz_plugin_osvr__PluginDisplay.data,
      qt_meta_data_rviz_plugin_osvr__PluginDisplay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *rviz_plugin_osvr::PluginDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rviz_plugin_osvr::PluginDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_rviz_plugin_osvr__PluginDisplay.stringdata0))
        return static_cast<void*>(const_cast< PluginDisplay*>(this));
    if (!strcmp(_clname, "Ogre::RenderTargetListener"))
        return static_cast< Ogre::RenderTargetListener*>(const_cast< PluginDisplay*>(this));
    return rviz::Display::qt_metacast(_clname);
}

int rviz_plugin_osvr::PluginDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = rviz::Display::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
