/****************************************************************************
** Meta object code from reading C++ file 'nauczyciel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../nauczyciel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nauczyciel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
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
struct qt_meta_tag_ZN10NauczycielE_t {};
} // unnamed namespace

template <> constexpr inline auto Nauczyciel::qt_create_metaobjectdata<qt_meta_tag_ZN10NauczycielE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Nauczyciel",
        "on_TeachGrdBtn_clicked",
        "",
        "on_TeachNoteBtn_clicked",
        "on_TeachAttndcBtn_clicked",
        "on_TeachSchdBtn_clicked",
        "on_TeachLogoutBtn_clicked",
        "on_TeachAddGrdBtn_clicked",
        "on_TeachDelGrdBtn_clicked",
        "on_TeachEditGrdBtn_clicked",
        "on_TeachAddAttndcBtn_clicked",
        "on_TeachDelAttndcBtn_clicked",
        "on_TeachEditAttndcBtn_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_TeachGrdBtn_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_TeachNoteBtn_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_TeachAttndcBtn_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_TeachSchdBtn_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_TeachLogoutBtn_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_TeachAddGrdBtn_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_TeachDelGrdBtn_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_TeachEditGrdBtn_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_TeachAddAttndcBtn_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_TeachDelAttndcBtn_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_TeachEditAttndcBtn_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Nauczyciel, qt_meta_tag_ZN10NauczycielE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Nauczyciel::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10NauczycielE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10NauczycielE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10NauczycielE_t>.metaTypes,
    nullptr
} };

void Nauczyciel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Nauczyciel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_TeachGrdBtn_clicked(); break;
        case 1: _t->on_TeachNoteBtn_clicked(); break;
        case 2: _t->on_TeachAttndcBtn_clicked(); break;
        case 3: _t->on_TeachSchdBtn_clicked(); break;
        case 4: _t->on_TeachLogoutBtn_clicked(); break;
        case 5: _t->on_TeachAddGrdBtn_clicked(); break;
        case 6: _t->on_TeachDelGrdBtn_clicked(); break;
        case 7: _t->on_TeachEditGrdBtn_clicked(); break;
        case 8: _t->on_TeachAddAttndcBtn_clicked(); break;
        case 9: _t->on_TeachDelAttndcBtn_clicked(); break;
        case 10: _t->on_TeachEditAttndcBtn_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Nauczyciel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Nauczyciel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10NauczycielE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Nauczyciel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
