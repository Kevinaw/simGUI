
#ifndef VOLT_AC_H
#define VOLT_AC_H

#include "component.h"


class Volt_ac : public Component  {
public:
  Volt_ac();
  ~Volt_ac();
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
};

#endif
