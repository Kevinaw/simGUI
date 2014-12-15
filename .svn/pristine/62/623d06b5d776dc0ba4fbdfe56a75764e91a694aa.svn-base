
#ifndef CHANGEDIALOG_H
#define CHANGEDIALOG_H

#include <QDialog>
#include <QRegExp>
#include <QGridLayout>

class Schematic;
class QLineEdit;
class QComboBox;
class QGridLayout;
class QRegExpValidator;


class ChangeDialog : public QDialog {
   Q_OBJECT
public:
  ChangeDialog(Schematic*);
 ~ChangeDialog();

private slots:
  void slotButtReplace();

private:
  bool matches(const QString&);

  Schematic *Doc;
  QGridLayout *all;   // the mother of all widgets
  QRegExpValidator  *Validator, *ValRestrict;
  QRegExp     Expr;
  QLineEdit   *CompNameEdit, *NewValueEdit;
  QComboBox   *CompTypeEdit, *PropNameEdit;
};

#endif
