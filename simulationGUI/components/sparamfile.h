
#ifndef SPARAMFILE_H
#define SPARAMFILE_H

#include "component.h"


class SParamFile : public MultiViewComponent  {
public:
  SParamFile();
 ~SParamFile() {};
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
  static Element* info1(QString&, char* &, bool getNewOne=false);
  static Element* info2(QString&, char* &, bool getNewOne=false);

  QString getSubcircuitFile();

protected:
  QString netlist();
  void createSymbol();
};

#endif
