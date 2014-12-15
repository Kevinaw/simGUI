
#ifndef MARKERDIALOG_H
#define MARKERDIALOG_H
#include "marker.h"
#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>




class MarkerDialog : public QDialog  {
Q_OBJECT
public:
  MarkerDialog(Marker *pm_, QWidget *parent=0);
 ~MarkerDialog();

private slots:
  void slotAcceptValues();

public:
  Marker *pMarker;

  QComboBox  *NumberBox;
  QLineEdit  *Precision;
  QLineEdit  *SourceImpedance;
  QCheckBox  *TransBox;
};

#endif
