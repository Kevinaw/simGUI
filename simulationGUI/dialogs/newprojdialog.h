
#ifndef NEWPROJDIALOG_H
#define NEWPROJDIALOG_H

#include <QDialog>
#include <QGridLayout>

class QLineEdit;
class QCheckBox;
class QPushButton;
class QGridLayout;

/**
  *@author Michael Margraf
  */

class NewProjDialog : public QDialog  {
  Q_OBJECT
public:
	NewProjDialog(QWidget *parent=0, const char *name=0);
	~NewProjDialog();

  QLineEdit   *ProjName;
  QCheckBox   *OpenProj;

private:
  QPushButton *ButtonOk, *ButtonCancel;
  QGridLayout *gbox;
};

#endif
