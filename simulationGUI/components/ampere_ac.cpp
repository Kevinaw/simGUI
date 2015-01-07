
#include "ampere_ac.h"


Ampere_ac::Ampere_ac()
{
  Description = QObject::tr("ideal ac current source");

  Arcs.append(new Arc(-12,-12, 24, 24,  0, 16*360,QPen(Qt::darkBlue,2)));
  Lines.append(new Line(-30,  0,-12,  0,QPen(Qt::darkBlue,2)));
  Lines.append(new Line( 30,  0, 12,  0,QPen(Qt::darkBlue,2)));
  Lines.append(new Line( -7,  0,  7,  0,QPen(Qt::darkBlue,3)));
  Lines.append(new Line(  6,  0,  0, -4,QPen(Qt::darkBlue,3)));
  Lines.append(new Line(  6,  0,  0,  4,QPen(Qt::darkBlue,3)));
  Arcs.append(new Arc( 12,  5,  6,  6,16*270, 16*180,QPen(Qt::darkBlue,2)));
  Arcs.append(new Arc( 12, 11,  6,  6, 16*90, 16*180,QPen(Qt::darkBlue,2)));

  Lines.append(new Line(-30, -11, -30, 11,QPen(Qt::darkBlue,3)));
  Lines.append(new Line( -36, -7,  -36, 7,QPen(Qt::darkBlue,3)));
  Lines.append(new Line( -42, -3,  -42, 3,QPen(Qt::darkBlue,3)));

  Ports.append(new Port( 30,  0));
//  Ports.append(new Port(-30,  0));

  x1 = -30; y1 = -14;
  x2 =  30; y2 =  16;

  tx = x1+4;
  ty = y2+4;
  Model = "Iac";
  Name  = "I";

  Props.append(new Property("I", "1 mA", true,
		QObject::tr("peak current in Ampere")));
  Props.append(new Property("f", "1 GHz", false,
		QObject::tr("frequency in Hertz")));
  Props.append(new Property("Phase", "0", false,
		QObject::tr("initial phase in degrees")));
  Props.append(new Property("Theta", "0", false,
		QObject::tr("damping factor (transient simulation only)")));

  rotate();  // fix historical flaw
}

Ampere_ac::~Ampere_ac()
{
}

Component* Ampere_ac::newOne()
{
  return new Ampere_ac();
}

Element* Ampere_ac::info(QString& Name, char* &BitmapFile, bool getNewOne)
{
  Name = QObject::tr("ac Current Source");
  BitmapFile = (char *) "ac_current";

  if(getNewOne)  return new Ampere_ac();
  return 0;
}
