
#ifndef IPROBE_H
#define IPROBE_H

#include "component.h"


class iProbe : public Component  {
public:
  iProbe();
  ~iProbe();
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
};

#endif
