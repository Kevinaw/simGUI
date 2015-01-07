
#ifndef MACHINE_H
#define MACHINE_H

#include "component.h"


class Machine : public Component  {
public:
  Machine();
  ~Machine();
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
};

#endif
