
#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QVBoxLayout>

class Schematic;
class QLineEdit;
class QTextEdit;
class QCheckBox;
class QComboBox;
class QVBoxLayout;
class QRegExpValidator;


class SettingsDialog : public QDialog  {
   Q_OBJECT
public:
  SettingsDialog(Schematic*);
 ~SettingsDialog();

private slots:
  void slotOK();
  void slotApply();

public:
  Schematic *Doc;

  QComboBox *Combo_Frame;
  QTextEdit *Input_Frame0;
  QLineEdit *Input_Frame1, *Input_Frame2, *Input_Frame3;
  QLineEdit *Input_DataSet, *Input_DataDisplay, *Input_Script;
  QLineEdit *Input_GridX, *Input_GridY;
  QCheckBox *Check_OpenDpl, *Check_GridOn, *Check_RunScript;

  QVBoxLayout *all;
  QRegExpValidator *valExpr;
};

#endif
