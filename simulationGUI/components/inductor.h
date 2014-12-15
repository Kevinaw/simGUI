
#ifndef INDUCTOR_H
#define INDUCTOR_H

#include "component.h"


class Inductor : public Component  {
public:
  Inductor();
 ~Inductor();
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
};

#endif
