
#ifndef SPICEDIALOG_H
#define SPICEDIALOG_H

#include <QDialog>
#include <QRegExp>
#include <QDir>
//Added by qt3to4:
#include <QTextStream>
#include <Q3VBoxLayout>

class Schematic;
class SpiceFile;
class QLineEdit;
class QPushButton;
class Q3ListBox;
class Q3ListBoxItem;
class QCheckBox;
class Q3VBoxLayout;
class QProcess;
class QRegExpValidator;
class QComboBox;
class SimguiApp;



class SpiceDialog : public QDialog {
   Q_OBJECT
public:
  SpiceDialog(SimguiApp*, SpiceFile*, Schematic*);
 ~SpiceDialog();

private slots:
  void slotButtOK();
  void slotButtCancel();
  void slotButtApply();
  void slotButtBrowse();
  void slotButtEdit();

  void slotButtAdd();
  void slotButtRemove();
  void slotAddPort(Q3ListBoxItem*);
  void slotRemovePort(Q3ListBoxItem*);

  void slotGetNetlist();
  void slotGetError();

  void slotSkipOut();
  void slotSkipErr();
  void slotGetPrepOut();
  void slotGetPrepErr();
  void slotPrepChanged(int);

protected slots:
    void reject();

private:
  bool loadSpiceNetList(const QString&);

  Q3VBoxLayout *all;   // the mother of all widgets
  QRegExpValidator  *Validator, *ValRestrict;
  QRegExp     Expr;
  Q3ListBox    *NodesList, *PortsList;
  QCheckBox   *FileCheck, *SimCheck;
  QLineEdit   *FileEdit, *CompNameEdit;
  QPushButton *ButtBrowse, *ButtEdit, *ButtAdd, *ButtRemove;
  QComboBox   *PrepCombo;
  SpiceFile   *Comp;
  Schematic   *Doc;
  bool        changed;
  int         currentPrep;

  QTextStream *prestream;
  QProcess *SimguiConv, *SpicePrep;
  QString Line, Error;  // to store the text read from SimguiConv
  int textStatus; // to store with text data SimguiConv will sent next

  SimguiApp* App;
};

#endif
