

#ifndef ID_TEXT_H
#define ID_TEXT_H

#include "painting.h"

#include <QString>
#include <Q3PtrList>

struct SubParameter {
  SubParameter(bool display_, const QString& Name_, const QString& Descr_)
     : display(display_), Name(Name_), Description(Descr_) { Type = ""; };
  SubParameter(bool display_, const QString& Name_, const QString& Descr_,
	       const QString& Type_)
     : display(display_), Name(Name_), Description(Descr_), Type(Type_) {};

  bool display;
  QString Name, Description, Type;
};


class ID_Text : public Painting  {
public:
  ID_Text(int cx_=0, int cy_=0);
 ~ID_Text();

  void paintScheme(Schematic*);
  void getCenter(int&, int&);
  void setCenter(int, int, bool relative=false);

  bool load(const QString&);
  QString save();
  QString saveCpp();
  QString saveJSON();
  void paint(ViewPainter*);
  bool getSelected(float, float, float);

  void rotate();
  void mirrorX();
  void mirrorY();
  bool Dialog();

  QString Prefix;
  Q3PtrList<SubParameter> Parameter;
};

#endif
