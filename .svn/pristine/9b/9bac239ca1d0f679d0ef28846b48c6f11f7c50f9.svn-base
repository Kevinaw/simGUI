
#ifndef RESISTOR_H
#define RESISTOR_H

#include "component.h"


class Resistor : public MultiViewComponent  {
public:
  Resistor(bool european=true);
 ~Resistor() {};
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
  static Element* info_us(QString&, char* &, bool getNewOne=false);

protected:
  void createSymbol();
};

#endif
