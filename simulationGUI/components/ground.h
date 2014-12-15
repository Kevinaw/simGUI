
#ifndef GROUND_H
#define GROUND_H

#include "component.h"


class Ground : public Component  {
public:
  Ground();
 ~Ground();
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);

protected:
  QString netlist();
};

#endif
