
#ifndef PORTSYMBOL_H
#define PORTSYMBOL_H

#include "painting.h"


class PortSymbol : public Painting  {
public:
  PortSymbol(int cx_=0, int cy_=0, const QString& numberStr_="1",
                                   const QString& nameStr_="");
 ~PortSymbol();

  void paintScheme(Schematic*);
  void getCenter(int&, int&);
  void setCenter(int, int, bool relative=false);

  bool load(const QString&);
  QString save();
  QString saveCpp();
  QString saveJSON();
  void paint(ViewPainter*);
  bool getSelected(float, float, float);
  void Bounding(int&, int&, int&, int&);

  void rotate();
  void mirrorX();
  void mirrorY();

  int Angel;
  QString numberStr, nameStr;
};

#endif
