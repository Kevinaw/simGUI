
#ifndef LIBCOMP_H
#define LIBCOMP_H

#include "component.h"
//Added by qt3to4:
#include <QTextStream>


class LibComp : public MultiViewComponent  {
public:
  LibComp();
 ~LibComp() {};
  Component* newOne();

  bool createSubNetlist(QTextStream *, QStringList&, int type=1);
  QString getSubcircuitFile();

protected:
  QString netlist();
  QString vhdlCode(int);
  QString verilogCode(int);
  void createSymbol();

private:
  int  loadSymbol();
  int  loadSection(const QString&, QString&, QStringList* i=0);
  QString createType();
};

#endif
