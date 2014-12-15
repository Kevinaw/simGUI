
#ifndef LABELDIALOG_H
#define LABELDIALOG_H

#include <QDialog>
#include <QRegExp>
#include <QGridLayout>
#include <QLabel>

class QLabel;
class QLineEdit;
class QPushButton;
class QGridLayout;
class QRegExpValidator;
class WireLabel;


class LabelDialog : public QDialog  {
Q_OBJECT
public:
  LabelDialog(WireLabel*, QWidget *parent=0);
 ~LabelDialog();

  QLineEdit  *NodeName, *InitValue;

private slots:
  void slotExtend();
  void slotOk();
  void slotCancel();

private:
  QPushButton *ButtonOk, *ButtonCancel, *ButtonMore;
  QGridLayout *gbox;
  QRegExpValidator *Validator1, *Validator2;
  QRegExp      Expr1, Expr2;
  QLabel      *Label2;

  WireLabel *pLabel;
};

#endif
