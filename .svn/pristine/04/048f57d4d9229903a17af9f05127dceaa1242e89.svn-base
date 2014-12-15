
#ifndef TIMINGDIAGRAM_H
#define TIMINGDIAGRAM_H

#include "tabdiagram.h"


class TimingDiagram : public TabDiagram  {
public: 
  TimingDiagram(int _cx=0, int _cy=0);
 ~TimingDiagram();

  Diagram* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
  void paint(ViewPainter*);
  int calcDiagram();
  int scroll(int);
  bool scrollTo(int, int, int);
};

#endif
