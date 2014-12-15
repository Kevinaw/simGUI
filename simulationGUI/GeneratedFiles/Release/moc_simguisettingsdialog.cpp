/****************************************************************************
** Meta object code from reading C++ file 'simguisettingsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dialogs/simguisettingsdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simguisettingsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SimguiSettingsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x08,
      31,   21,   21,   21, 0x08,
      43,   21,   21,   21, 0x08,
      60,   21,   21,   21, 0x08,
      80,   21,   21,   21, 0x08,
     100,   21,   21,   21, 0x08,
     118,   21,   21,   21, 0x08,
     139,   21,   21,   21, 0x08,
     158,   21,   21,   21, 0x08,
     176,   21,   21,   21, 0x08,
     195,   21,   21,   21, 0x08,
     211,   21,   21,   21, 0x08,
     232,   21,   21,   21, 0x08,
     252,   21,   21,   21, 0x08,
     273,   21,   21,   21, 0x08,
     294,   21,   21,   21, 0x08,
     312,  310,   21,   21, 0x08,
     338,  310,   21,   21, 0x08,
     368,   21,   21,   21, 0x08,
     388,   21,   21,   21, 0x08,
     411,   21,   21,   21, 0x08,
     431,   21,   21,   21, 0x08,
     453,   21,   21,   21, 0x08,
     467,   21,   21,   21, 0x08,
     495,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SimguiSettingsDialog[] = {
    "SimguiSettingsDialog\0\0slotOK()\0"
    "slotApply()\0slotFontDialog()\0"
    "slotBGColorDialog()\0slotDefaultValues()\0"
    "slotAddFileType()\0slotRemoveFileType()\0"
    "slotColorComment()\0slotColorString()\0"
    "slotColorInteger()\0slotColorReal()\0"
    "slotColorCharacter()\0slotColorDataType()\0"
    "slotColorAttribute()\0slotColorDirective()\0"
    "slotColorTask()\0,\0slotTableClicked(int,int)\0"
    "slotPathTableClicked(int,int)\0"
    "slotHomeDirBrowse()\0slotAdmsXmlDirBrowse()\0"
    "slotAscoDirBrowse()\0slotOctaveDirBrowse()\0"
    "slotAddPath()\0slotAddPathWithSubFolders()\0"
    "slotRemovePath()\0"
};

void SimguiSettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SimguiSettingsDialog *_t = static_cast<SimguiSettingsDialog *>(_o);
        switch (_id) {
        case 0: _t->slotOK(); break;
        case 1: _t->slotApply(); break;
        case 2: _t->slotFontDialog(); break;
        case 3: _t->slotBGColorDialog(); break;
        case 4: _t->slotDefaultValues(); break;
        case 5: _t->slotAddFileType(); break;
        case 6: _t->slotRemoveFileType(); break;
        case 7: _t->slotColorComment(); break;
        case 8: _t->slotColorString(); break;
        case 9: _t->slotColorInteger(); break;
        case 10: _t->slotColorReal(); break;
        case 11: _t->slotColorCharacter(); break;
        case 12: _t->slotColorDataType(); break;
        case 13: _t->slotColorAttribute(); break;
        case 14: _t->slotColorDirective(); break;
        case 15: _t->slotColorTask(); break;
        case 16: _t->slotTableClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->slotPathTableClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->slotHomeDirBrowse(); break;
        case 19: _t->slotAdmsXmlDirBrowse(); break;
        case 20: _t->slotAscoDirBrowse(); break;
        case 21: _t->slotOctaveDirBrowse(); break;
        case 22: _t->slotAddPath(); break;
        case 23: _t->slotAddPathWithSubFolders(); break;
        case 24: _t->slotRemovePath(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SimguiSettingsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SimguiSettingsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SimguiSettingsDialog,
      qt_meta_data_SimguiSettingsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimguiSettingsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimguiSettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimguiSettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimguiSettingsDialog))
        return static_cast<void*>(const_cast< SimguiSettingsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SimguiSettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
