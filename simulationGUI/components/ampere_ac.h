#ifndef AMPERE_AC_H
#define AMPERE_AC_H

#include "component.h"


class Ampere_ac : public Component  {
public:
  Ampere_ac();
  ~Ampere_ac();
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
};

#endif
