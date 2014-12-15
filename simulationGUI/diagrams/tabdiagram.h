
#ifndef TABDIAGRAM_H
#define TABDIAGRAM_H

#include "diagram.h"


class TabDiagram : public Diagram  {
public: 
  TabDiagram(int _cx=0, int _cy=0);
 ~TabDiagram();

  virtual Diagram* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);
  virtual void paint(ViewPainter*);
  virtual int calcDiagram();
  virtual int scroll(int);
  virtual bool scrollTo(int, int, int);

  void createAxisLabels() {};   // no labels in this diagram

protected:
  void calcData(Graph*) {};  // no graph data
};

#endif
