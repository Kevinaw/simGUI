
#ifndef SOURCE_AC_H
#define SOURCE_AC_H

#include "component.h"


class Source_ac : public Component  {
public:
  Source_ac();
  ~Source_ac();
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
};

#endif
