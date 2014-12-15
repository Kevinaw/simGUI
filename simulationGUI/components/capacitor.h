
#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "component.h"


class Capacitor : public MultiViewComponent  {
public:
  Capacitor();
 ~Capacitor() {};
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);

protected:
  void createSymbol();
};

#endif
