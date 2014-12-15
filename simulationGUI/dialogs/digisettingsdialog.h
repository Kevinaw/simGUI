
#ifndef DIGISETTINGSDIALOG_H
#define DIGISETTINGSDIALOG_H

#include <QDialog>
#include <QRegExp>
#include <QLabel>

class TextDoc;
class QLineEdit;
class QPushButton;
class QRegExpValidator;
class QLabel;
class QRadioButton;


class DigiSettingsDialog : public QDialog  {
Q_OBJECT
public:
  DigiSettingsDialog(TextDoc*);
 ~DigiSettingsDialog();

  QString SimTime;
  QLineEdit *TimeEdit, *LibEdit, *NameEdit;
  QLabel *TimeLabel, *LibLabel, *NameLabel;
  QRadioButton *simRadio, *comRadio;

private slots:
  void slotOk();
  void slotChangeMode(int);

private:
  TextDoc *Doc;
  QRegExp Expr;
  QRegExpValidator *Validator;
};

#endif
