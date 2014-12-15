
#ifndef SMITHDIAGRAM_H
#define SMITHDIAGRAM_H

#include "diagram.h"


class SmithDiagram : public Diagram  {
public: 
  SmithDiagram(int _cx=0, int _cy=0, bool ImpMode=true);
 ~SmithDiagram();


  Diagram* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
  static Element* info_y(QString&, char* &, bool getNewOne=false);
  int  calcDiagram();
  void calcLimits();
  void calcCoordinate(double* &, double* &, double* &, float*, float*, Axis*);
};

#endif
