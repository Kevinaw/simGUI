
#include "newprojdialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QGridLayout>


NewProjDialog::NewProjDialog(QWidget *parent, const char *name)
                             : QDialog(parent, name, true)
{
  setWindowTitle(tr("Create new project"));

  gbox = new QGridLayout(this);
  QLabel *Label1 = new QLabel(tr("Project name:"));
  gbox->addWidget(Label1,0,0);

  ProjName = new QLineEdit(this);
  ProjName->setMinimumWidth(250);
  gbox->addMultiCellWidget(ProjName,0,0,1,2);
  OpenProj = new QCheckBox(tr("open new project"));
  OpenProj->setChecked(true);
  gbox->addMultiCellWidget(OpenProj,1,1,1,2);

  ButtonOk = new QPushButton(tr("Create"));
  gbox->addWidget(ButtonOk,2,1);
  ButtonCancel = new QPushButton(tr("Cancel"));
  gbox->addWidget(ButtonCancel,2,2);

  connect(ButtonOk, SIGNAL(clicked()), SLOT(accept()));
  connect(ButtonCancel, SIGNAL(clicked()), SLOT(reject()));

  ButtonOk->setDefault(true);
  setFocusProxy(ProjName);
}

NewProjDialog::~NewProjDialog()
{
  delete gbox;
}
