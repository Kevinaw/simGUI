
#ifndef VPROBE_H
#define VPROBE_H

#include "component.h"


class vProbe : public Component  {
public:
  vProbe();
 ~vProbe();
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
};

#endif
