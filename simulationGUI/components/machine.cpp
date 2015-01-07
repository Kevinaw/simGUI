
#include "machine.h"


Machine::Machine()
{
  Description = QObject::tr("Machine");

  Arcs.append(new Arc(-12,-12, 24, 24,     0, 16*360,QPen(Qt::darkBlue,2)));
  //Lines.append(new Line(-30,  0,-12,  0,QPen(Qt::darkBlue,2)));
  Lines.append(new Line( 30,  0, 12,  0,QPen(Qt::darkBlue,2)));

  Lines.append(new Line(0,  0,  -6, -6,QPen(Qt::darkBlue,2)));
  Lines.append(new Line(0,  0,  6, -6,QPen(Qt::darkBlue,2)));
  Lines.append(new Line( -6, -6, -6, 6,QPen(Qt::darkBlue,2)));
  Lines.append(new Line( 6, -6, 6, 6,QPen(Qt::darkBlue,2)));

  Ports.append(new Port( 30,  0));
  //Ports.append(new Port(-30,  0));

  x1 = -30; y1 = -15;
  x2 =  30; y2 =  15;

  tx = x1+4;
  ty = y2+4;
  Model = "Machine";
  Name  = "M";

  Props.append(new Property("u", "1e-6", true,
		QObject::tr("voltage power spectral density in V^2/Hz")));
  Props.append(new Property("e", "0", false,
		QObject::tr("frequency exponent")));
  Props.append(new Property("c", "1", false,
		QObject::tr("frequency coefficient")));
  Props.append(new Property("a", "0", false,
		QObject::tr("additive frequency term")));

  //rotate();  // fix historical flaw
}

Machine::~Machine()
{
}

Component* Machine::newOne()
{
  return new Machine();
}

Element* Machine::info(QString& Name, char* &BitmapFile, bool getNewOne)
{
  Name = QObject::tr("Machine");
  BitmapFile = (char *) "machine";

  if(getNewOne)  return new Machine();
  return 0;
}
