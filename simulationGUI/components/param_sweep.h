
#ifndef PARAM_SWEEP_H
#define PARAM_SWEEP_H

#include "component.h"


class Param_Sweep : public Component  {
public:
  Param_Sweep();
  ~Param_Sweep();
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
  void recreate(Schematic*);
};

#endif
