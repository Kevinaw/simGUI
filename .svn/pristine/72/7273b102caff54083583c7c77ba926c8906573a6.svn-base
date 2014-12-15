
#ifndef FILLDIALOG_H
#define FILLDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>

class QVBoxLayout;
class QLabel;
class QIntValidator;
class QCheckBox;
class QComboBox;
class QPushButton;
class QLineEdit;

/**
  *@author Michael Margraf
  */

class FillDialog : public QDialog  {
Q_OBJECT
public:
  FillDialog(const QString& _Caption, bool show=true, QWidget *parent=0);
  ~FillDialog();

public slots:
  void slotCheckFilled(bool on);

private slots:
  void slotSetColor();
  void slotSetFillColor();

public:
  QLabel        *FillLabel1, *FillLabel2;
  QCheckBox     *CheckFilled;
  QLineEdit     *LineWidth;
  QPushButton   *ColorButt, *FillColorButt;
  QComboBox     *StyleBox, *FillStyleBox;

  QVBoxLayout   *all;
  QIntValidator *val100;
};

#endif
