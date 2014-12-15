
#ifndef SWEEPDIALOG_H
#define SWEEPDIALOG_H

#include <QDialog>
#include <QRegExp>
#include <Q3PtrList>

#include <QSpinBox>
#include <QGridLayout>

#include "node.h"

class Graph;
class Schematic;
class QGridLayout;


class mySpinBox : public QSpinBox {
   Q_OBJECT
public:
  mySpinBox(int, int, int, double*, QWidget*);

protected:
  QString textFromValue(int);
  QValidator::State validate ( QString & text, int & pos ) const;

private:
  double *Values;
  int ValueSize;
};



class SweepDialog : public QDialog {
   Q_OBJECT
public:
  SweepDialog(Schematic*);
 ~SweepDialog();

private slots:
  void slotNewValue(int);

private:
  Graph* setBiasPoints();

  QGridLayout *all;   // the mother of all widgets
  Q3PtrList<mySpinBox> BoxList;

  Graph *pGraph;
  Schematic *Doc;
  Q3PtrList<Node> NodeList;
  Q3PtrList<double> ValueList;
};

#endif
