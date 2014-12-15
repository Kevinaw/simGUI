
#ifndef VASETTINGSDIALOG_H
#define VASETTINGSDIALOG_H

#include <QDialog>
#include <QRegExp>
#include <QLabel>

class TextDoc;
class QLineEdit;
class QPushButton;
class QRegExpValidator;
class QLabel;
class QCheckBox;
class QButtonGroup;
class QVBoxLayout;

class VASettingsDialog : public QDialog  {
Q_OBJECT
public:
  VASettingsDialog (TextDoc *);
 ~VASettingsDialog ();

  QLineEdit * IconEdit, * OutputEdit, * NameEdit, * ShortDescEdit,
    * LongDescEdit;
  QPushButton * BrowseButt;
  QLabel * IconButt;
  QCheckBox * RecreateCheck;
  QButtonGroup * toggleGroupDev, * toggleGroupTyp;

private slots:
  void slotOk ();
  void slotBrowse ();

private:
  TextDoc * Doc;
  QRegExp Expr;
  QRegExpValidator * Validator;
  QVBoxLayout *vLayout;
};

#endif
