
#ifndef EQUATION_H
#define EQUATION_H

#include "component.h"


class Equation : public Component  {

public:
  Equation();
  ~Equation();
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);

protected:
  QString vhdlCode(int);
  QString verilogCode(int);
};

#endif
