
#include "volt_ac.h"


Volt_ac::Volt_ac()
{
  Description = QObject::tr("ideal ac voltage source");

  Arcs.append(new Arc(-12,-12, 24, 24,     0, 16*360,QPen(Qt::darkBlue,2)));
  Arcs.append(new Arc( -3, -7,  7,  7,16*270, 16*180,QPen(Qt::darkBlue,2)));
  Arcs.append(new Arc( -3,  0,  7,  7, 16*90, 16*180,QPen(Qt::darkBlue,2)));
  Lines.append(new Line(-30,  0,-12,  0,QPen(Qt::darkBlue,2)));
  Lines.append(new Line( 30,  0, 12,  0,QPen(Qt::darkBlue,2)));
  Lines.append(new Line( 18,  5, 18, 11,QPen(Qt::red,1)));
  Lines.append(new Line( 21,  8, 15,  8,QPen(Qt::red,1)));
//  Lines.append(new Line(-18,  5,-18, 11,QPen(Qt::black,1)));
    
  Lines.append(new Line(-30, -11, -30, 11,QPen(Qt::darkBlue,3)));
  Lines.append(new Line( -36, -7,  -36, 7,QPen(Qt::darkBlue,3)));
  Lines.append(new Line( -42, -3,  -42, 3,QPen(Qt::darkBlue,3)));

  Ports.append(new Port( 30,  0));
  //Ports.append(new Port(-30,  0));

  x1 = -30; y1 = -14;
  x2 =  30; y2 =  14;

  tx = x1+4;
  ty = y2+4;
  Model = "Vac";
  Name  = "V";

  Props.append(new Property("U", "1 V", true,
		QObject::tr("peak voltage in Volts")));
  Props.append(new Property("f", "1 GHz", false,
		QObject::tr("frequency in Hertz")));
  Props.append(new Property("Phase", "0", false,
		QObject::tr("initial phase in degrees")));
  Props.append(new Property("Theta", "0", false,
		QObject::tr("damping factor (transient simulation only)")));

  rotate();  // fix historical flaw
}

Volt_ac::~Volt_ac()
{
}

Component* Volt_ac::newOne()
{
  return new Volt_ac();
}

Element* Volt_ac::info(QString& Name, char* &BitmapFile, bool getNewOne)
{
  Name = QObject::tr("ac Voltage Source");
  BitmapFile = (char *) "ac_voltage";

  if(getNewOne)  return new Volt_ac();
  return 0;
}
