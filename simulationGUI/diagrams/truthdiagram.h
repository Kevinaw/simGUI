
#ifndef TRUTHDIAGRAM_H
#define TRUTHDIAGRAM_H

#include "tabdiagram.h"


class TruthDiagram : public TabDiagram  {
public: 
  TruthDiagram(int _cx=0, int _cy=0);
 ~TruthDiagram();

  Diagram* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
  int calcDiagram();
};

#endif
