/*!
 * \file main.cpp
 * \brief Implementation of the main application.
 */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <QtGui>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>

#include <QApplication>
#include <QString>
#include <QStringList>
#include <QTextCodec>
#include <QTranslator>
#include <QFile>
#include <QMessageBox>
#include <QRegExp>

#include "simgui.h"
#include "main.h"
#include "node.h"

#include "schematic.h"
#include "module.h"

#ifdef _WIN32
#include <Windows.h>  //for OutputDebugString
#endif

tSimguiSettings SimguiSettings;

SimguiApp *SimguiMain = 0;  // the Simgui application itself
QString lastDir;    // to remember last directory for several dialogs
QStringList simguiPathList;

// #########################################################################
// Loads the settings file and stores the settings.
bool loadSettings()
{
    QSettings settings("simgui","simgui");

    if(settings.contains("x"))SimguiSettings.x=settings.value("x").toInt();
    if(settings.contains("y"))SimguiSettings.y=settings.value("y").toInt();
    if(settings.contains("dx"))SimguiSettings.dx=settings.value("dx").toInt();
    if(settings.contains("dy"))SimguiSettings.dy=settings.value("dy").toInt();
    if(settings.contains("font"))SimguiSettings.font.fromString(settings.value("font").toString());
    if(settings.contains("largeFontSize"))SimguiSettings.largeFontSize=settings.value("largeFontSize").toDouble();
    if(settings.contains("maxUndo"))SimguiSettings.maxUndo=settings.value("maxUndo").toInt();
    if(settings.contains("NodeWiring"))SimguiSettings.NodeWiring=settings.value("NodeWiring").toInt();
    if(settings.contains("BGColor"))SimguiSettings.BGColor.setNamedColor(settings.value("BGColor").toString());
    if(settings.contains("Editor"))SimguiSettings.Editor=settings.value("Editor").toString();
    if(settings.contains("FileTypes"))SimguiSettings.FileTypes=settings.value("FileTypes").toStringList();
    if(settings.contains("Language"))SimguiSettings.Language=settings.value("Language").toString();
    if(settings.contains("Comment"))SimguiSettings.Comment.setNamedColor(settings.value("Comment").toString());
    if(settings.contains("String"))SimguiSettings.String.setNamedColor(settings.value("String").toString());
    if(settings.contains("Integer"))SimguiSettings.Integer.setNamedColor(settings.value("Integer").toString());
    if(settings.contains("Real"))SimguiSettings.Real.setNamedColor(settings.value("Real").toString());
    if(settings.contains("Character"))SimguiSettings.Character.setNamedColor(settings.value("Character").toString());
    if(settings.contains("Type"))SimguiSettings.Type.setNamedColor(settings.value("Type").toString());
    if(settings.contains("Attribute"))SimguiSettings.Attribute.setNamedColor(settings.value("Attribute").toString());
    if(settings.contains("Directive"))SimguiSettings.Directive.setNamedColor(settings.value("Directive").toString());
    if(settings.contains("Task"))SimguiSettings.Comment.setNamedColor(settings.value("Task").toString());

    if(settings.contains("Editor"))SimguiSettings.Editor = settings.value("Editor").toString();
    //if(settings.contains("BinDir"))SimguiSettings.BinDir = settings.value("BinDir").toString();
    //if(settings.contains("LangDir"))SimguiSettings.LangDir = settings.value("LangDir").toString();
    //if(settings.contains("LibDir"))SimguiSettings.LibDir = settings.value("LibDir").toString();
    if(settings.contains("AdmsXmlBinDir"))SimguiSettings.AdmsXmlBinDir = settings.value("AdmsXmlBinDir").toString();
    if(settings.contains("AscoBinDir"))SimguiSettings.AscoBinDir = settings.value("AscoBinDir").toString();
    //if(settings.contains("OctaveDir"))SimguiSettings.OctaveDir = settings.value("OctaveDir").toString();
    //if(settings.contains("ExamplesDir"))SimguiSettings.ExamplesDir = settings.value("ExamplesDir").toString();
    //if(settings.contains("DocDir"))SimguiSettings.DocDir = settings.value("DocDir").toString();
    if(settings.contains("OctaveBinDir"))SimguiSettings.OctaveBinDir.setPath(settings.value("OctaveBinDir").toString());
    if(settings.contains("SimguiHomeDir"))
      if(settings.value("SimguiHomeDir").toString() != "")
         SimguiSettings.SimguiHomeDir.setPath(settings.value("SimguiHomeDir").toString());
    SimguiSettings.SimguiWorkDir = SimguiSettings.SimguiHomeDir;

    if (settings.contains("IngnoreVersion")) SimguiSettings.IgnoreFutureVersion = settings.value("IngnoreVersion").toBool();
    else SimguiSettings.IgnoreFutureVersion = false;


    SimguiSettings.RecentDocs = settings.value("RecentDocs").toString().split("*",QString::SkipEmptyParts);
    SimguiSettings.numRecentDocs = SimguiSettings.RecentDocs.count();


    // If present read in the list of directory paths in which Simgui should
    // search for subcircuit schematics
    int npaths = settings.beginReadArray("Paths");
    for (int i = 0; i < npaths; ++i)
    {
        settings.setArrayIndex(i);
        QString apath = settings.value("path").toString();
        simguiPathList.append(apath);
    }
    settings.endArray();

    SimguiSettings.numRecentDocs = 0;

    return true;
}

// #########################################################################
// Saves the settings in the settings file.
bool saveApplSettings(SimguiApp *simgui)
{
    QSettings settings ("simgui","simgui");

    settings.setValue("x", SimguiSettings.x);
    settings.setValue("y", SimguiSettings.y);
    settings.setValue("dx", SimguiSettings.dx);
    settings.setValue("dy", SimguiSettings.dy);
    settings.setValue("font", SimguiSettings.font.toString());
    settings.setValue("largeFontSize", SimguiSettings.largeFontSize);
    settings.setValue("maxUndo", SimguiSettings.maxUndo);
    settings.setValue("NodeWiring", SimguiSettings.NodeWiring);
    settings.setValue("BGColor", SimguiSettings.BGColor.name());
    settings.setValue("Editor", SimguiSettings.Editor);
    settings.setValue("FileTypes", SimguiSettings.FileTypes);
    settings.setValue("Language", SimguiSettings.Language);
    settings.setValue("Comment", SimguiSettings.Comment.name());
    settings.setValue("String", SimguiSettings.String.name());
    settings.setValue("Integer", SimguiSettings.Integer.name());
    settings.setValue("Real", SimguiSettings.Real.name());
    settings.setValue("Character", SimguiSettings.Character.name());
    settings.setValue("Type", SimguiSettings.Type.name());
    settings.setValue("Attribute", SimguiSettings.Attribute.name());
    settings.setValue("Directive", SimguiSettings.Directive.name());
    settings.setValue("Task", SimguiSettings.Comment.name());
    settings.setValue("Editor", SimguiSettings.Editor);
    //settings.setValue("BinDir", SimguiSettings.BinDir);
    //settings.setValue("LangDir", SimguiSettings.LangDir);
    //settings.setValue("LibDir", SimguiSettings.LibDir);
    settings.setValue("AdmsXmlBinDir", SimguiSettings.AdmsXmlBinDir.canonicalPath());
    settings.setValue("AscoBinDir", SimguiSettings.AscoBinDir.canonicalPath());
    //settings.setValue("OctaveDir", SimguiSettings.OctaveDir);
    //settings.setValue("ExamplesDir", SimguiSettings.ExamplesDir);
    //settings.setValue("DocDir", SimguiSettings.DocDir);
    settings.setValue("OctaveBinDir", SimguiSettings.OctaveBinDir.canonicalPath());
    settings.setValue("SimguiHomeDir", SimguiSettings.SimguiHomeDir.canonicalPath());
    settings.setValue("IngnoreVersion",SimguiSettings.IgnoreFutureVersion);

    // Copy the list of directory paths in which Simgui should
    // search for subcircuit schematics from simguiPathList
    settings.remove("Paths");
    settings.beginWriteArray("Paths");
    int i = 0;
    foreach(QString path, simguiPathList) {
         settings.setArrayIndex(i);
         settings.setValue("path", path);
         i++;
     }
     settings.endArray();

  return true;

}

/*!
 * \brief simguiMessageOutput handles qDebug, qWarning, qCritical, qFatal.
 * \param type Message type (Qt enum)
 * \param msg Message
 *
 * The message handler is used to get control of the messages.
 * Particulary on Windows, as the messages are sent to the debugger and do not
 * show on the terminal. The handler could aslo be extended to create a log
 * mechanism.
 * <http://qt-project.org/doc/qt-4.8/debug.html#warning-and-debugging-messages>
 * <http://qt-project.org/doc/qt-4.8/qtglobal.html#qInstallMsgHandler>
 */
void simguiMessageOutput(QtMsgType type, const char *msg)
{
  switch (type) {
  case QtDebugMsg:
    fprintf(stderr, "Debug: %s\n", msg);
    break;
  case QtWarningMsg:
    fprintf(stderr, "Warning: %s\n", msg);
    break;
  case QtCriticalMsg:
    fprintf(stderr, "Critical: %s\n", msg);
    break;
  case QtFatalMsg:
    fprintf(stderr, "Fatal: %s\n", msg);
    abort();
  }

#ifdef _WIN32
  OutputDebugStringA(msg);
#endif
}

// #########################################################################
// #########################################################################
// ##########                                                     ##########
// ##########            MOVE SOMEWHERE ELSE START                ##########
// ##########                                                     ##########
// #########################################################################



QString complexRect(double real, double imag, int Precision)
{
  QString Text;
  if(fabs(imag) < 1e-250) Text = QString::number(real,'g',Precision);
  else {
    Text = QString::number(imag,'g',Precision);
    if(Text.at(0) == '-') {
      Text.replace(0,1,'j');
      Text = '-'+Text;
    }
    else  Text = "+j"+Text;
    Text = QString::number(real,'g',Precision) + Text;
  }
  return Text;
}

QString complexDeg(double real, double imag, int Precision)
{
  QString Text;
  if(fabs(imag) < 1e-250) Text = QString::number(real,'g',Precision);
  else {
    Text  = QString::number(sqrt(real*real+imag*imag),'g',Precision) + " / ";
    Text += QString::number(180.0/M_PI*atan2(imag,real),'g',Precision) + QString::fromUtf8("°");
  }
  return Text;
}

QString complexRad (double real, double imag, int Precision)
{
  QString Text;
  if(fabs(imag) < 1e-250) Text = QString::number(real,'g',Precision);
  else {
    Text  = QString::number(sqrt(real*real+imag*imag),'g',Precision);
    Text += " / " + QString::number(atan2(imag,real),'g',Precision) + "rad";
  }
  return Text;
}

// #########################################################################
QString StringNum(double num, char form, int Precision)
{
  int a = 0;
  char *p, Buffer[512], Format[6] = "%.00g";

  if(Precision < 0) {
    Format[1]  = form;
    Format[2]  = 0;
  }
  else {
    Format[4]  = form;
    Format[2] += Precision / 10;
    Format[3] += Precision % 10;
  }
  sprintf(Buffer, Format, num);
  p = strchr(Buffer, 'e');
  if(p) {
    p++;
    if(*(p++) == '+') { a = 1; }   // remove '+' of exponent
    if(*p == '0') { a++; p++; }    // remove leading zeros of exponent
    if(a > 0)
      do {
        *(p-a) = *p;
      } while(*(p++) != 0);    // override characters not needed
  }

  return QString(Buffer);
}

// #########################################################################
QString StringNiceNum(double num)
{
  char Format[6] = "%.8e";
  if(fabs(num) < 1e-250)  return QString("0");  // avoid many problems
  if(fabs(log10(fabs(num))) < 3.0)  Format[3] = 'g';

  int a = 0;
  char *p, *pe, Buffer[512];

  sprintf(Buffer, Format, num);
  p = pe = strchr(Buffer, 'e');
  if(p) {
    if(*(++p) == '+') { a = 1; }    // remove '+' of exponent
    if(*(++p) == '0') { a++; p++; } // remove leading zeros of exponent
    if(a > 0)
      do {
        *(p-a) = *p;
      } while(*(p++) != 0);  // override characters not needed

    // In 'g' format, trailing zeros are already cut off !!!
    p = strchr(Buffer, '.');
    if(p) {
      if(!pe)  pe = Buffer + strlen(Buffer);
      p = pe-1;
      while(*p == '0')   // looking for unneccessary zero characters
        if((--p) <= Buffer)  break;
      if(*p != '.')  p++;  // no digit after decimal point ?
      while( (*(p++) = *(pe++)) != 0 ) ;  // overwrite zero characters
    }
  }

  return QString(Buffer);
}

// #########################################################################
void str2num(const QString& s_, double& Number, QString& Unit, double& Factor)
{
  QString str = s_.stripWhiteSpace();

/*  int i=0;
  bool neg = false;
  if(str[0] == '-') {      // check sign
    neg = true;
    i++;
  }
  else if(str[0] == '+')  i++;

  double num = 0.0;
  for(;;) {
    if(str[i] >= '0')  if(str[i] <= '9') {
      num = 10.0*num + double(str[i]-'0');
    }
  }*/

  QRegExp Expr( QRegExp("[^0-9\\x2E\\x2D\\x2B]") );
  int i = str.find( Expr );
  if(i >= 0)
    if((str.at(i).latin1() | 0x20) == 'e') {
      int j = str.find( Expr , ++i);
      if(j == i)  j--;
      i = j;
    }

  Number = str.left(i).toDouble();
  Unit   = str.mid(i).stripWhiteSpace();
  if(Unit.length()>0)
  {
    switch(Unit.at(0).latin1()) {
      case 'T': Factor = 1e12;  break;
      case 'G': Factor = 1e9;   break;
      case 'M': Factor = 1e6;   break;
      case 'k': Factor = 1e3;   break;
      case 'c': Factor = 1e-2;  break;
      case 'm': Factor = 1e-3;  break;
      case 'u': Factor = 1e-6;  break;
      case 'n': Factor = 1e-9;  break;
      case 'p': Factor = 1e-12; break;
      case 'f': Factor = 1e-15; break;
  //    case 'd':
      default:  Factor = 1.0;
    }
  }
  else
  {
    Factor = 1.0;
  }

  return;
}

// #########################################################################
QString num2str(double Num)
{
  char c = 0;
  double cal = fabs(Num);
  if(cal > 1e-20) {
    cal = log10(cal) / 3.0;
    if(cal < -0.2)  cal -= 0.98;
    int Expo = int(cal);

    if(Expo >= -5) if(Expo <= 4)
      switch(Expo) {
        case -5: c = 'f'; break;
        case -4: c = 'p'; break;
        case -3: c = 'n'; break;
        case -2: c = 'u'; break;
        case -1: c = 'm'; break;
        case  1: c = 'k'; break;
        case  2: c = 'M'; break;
        case  3: c = 'G'; break;
        case  4: c = 'T'; break;
      }

    if(c)  Num /= pow(10.0, double(3*Expo));
  }

  QString Str = QString::number(Num);
  if(c)  Str += c;

  return Str;
}

// #########################################################################
void convert2Unicode(QString& Text)
{
  bool ok;
  int i = 0;
  QString n;
  unsigned short ch;
  while((i=Text.find("\\x", i)) >= 0) {
    n = Text.mid(i, 6);
    ch = n.mid(2).toUShort(&ok, 16);
    if(ok)  Text.replace(n, QChar(ch));
    i++;
  }
  Text.replace("\\n", "\n");
  Text.replace("\\\\", "\\");
}

// #########################################################################
void convert2ASCII(QString& Text)
{
  Text.replace('\\', "\\\\");
  Text.replace('\n', "\\n");

  int i = 0;
  QChar ch;
  char Str[8];
  while(Text.size()<i) {  // convert special characters
    if(ch > QChar(0x7F)) {
      sprintf(Str, "\\x%04X", ch.unicode());
      Text.replace(ch, Str);
    }
  }
}

// #########################################################################
// Converts a path to an absolute path and resolves paths relative to the
// Simgui home directory
QString properAbsFileName(const QString& Name)
{
  QString s = Name;
  QFileInfo Info(s);

  if(Info.isRelative())
  {
      // if it's a relative file, look for it relative to the
      // working directory (the simgui home directory)
      s = SimguiSettings.SimguiWorkDir.filePath(s);
  }
  // return the clean path
  return QDir::cleanPath(s);
}

// #########################################################################
QString properFileName(const QString& Name)
{
  QFileInfo Info(Name);
  return Info.fileName();
}

// #########################################################################
// Takes a file name (with path) and replaces all special characters.
QString properName(const QString& Name)
{
  QString s = Name;
  QFileInfo Info(s);
  if(Info.extension() == "sch")
    s = s.left(s.length()-4);
  if(s.at(0) <= '9') if(s.at(0) >= '0')
    s = 'n' + s;
  s.replace(QRegExp("\\W"), "_"); // none [a-zA-Z0-9] into "_"
  s.replace("__", "_");  // '__' not allowed in VHDL
  if(s.at(0) == '_')
    s = 'n' + s;
  return s;
}

// #########################################################################
// Creates and returns delay time for VHDL entities.
bool VHDL_Delay(QString& td, const QString& Name)
{
  if(strtod(td.latin1(), 0) != 0.0) {  // delay time property
    if(!VHDL_Time(td, Name))
      return false;    // time has not VHDL format
    td = " after " + td;
    return true;
  }
  else if(isalpha(td.latin1()[0])) {
    td = " after " + td;
    return true;
  }
  else {
    td = "";
    return true;
  }
}

// #########################################################################
// Checks and corrects a time (number & unit) according VHDL standard.
bool VHDL_Time(QString& t, const QString& Name)
{
  char *p;
  double Time = strtod(t.latin1(), &p);
  while(*p == ' ') p++;
  for(;;) {
    if(Time >= 0.0) {
      if(strcmp(p, "fs") == 0)  break;
      if(strcmp(p, "ps") == 0)  break;
      if(strcmp(p, "ns") == 0)  break;
      if(strcmp(p, "us") == 0)  break;
      if(strcmp(p, "ms") == 0)  break;
      if(strcmp(p, "sec") == 0) break;
      if(strcmp(p, "min") == 0) break;
      if(strcmp(p, "hr") == 0)  break;
    }
    t = QString::fromUtf8("§")  + QObject::tr("Error: Wrong time format in \"%1\". Use positive number with units").arg(Name)
            + " fs, ps, ns, us, ms, sec, min, hr.\n";
    return false;
  }

  t = QString::number(Time) + " " + QString(p);  // the space is mandatory !
  return true;
}

// #########################################################################
// Returns parameters for Verilog modules.
QString Verilog_Param(const QString Value)
{
  if(strtod(Value.latin1(), 0) != 0.0) {
    QString td = Value;
    if(!Verilog_Time(td, "parameter"))
      return Value;
    else
      return td;
  }
  else
    return Value;
}

// #########################################################################
// Creates and returns delay time for Verilog modules.
bool Verilog_Delay(QString& td, const QString& Name)
{
  if(strtod(td.latin1(), 0) != 0.0) {  // delay time property
    if(!Verilog_Time(td, Name))
      return false;    // time has not Verilog format
    td = " #" + td;
    return true;
  }
  else if(isalpha(td.latin1()[0])) {
    td = " #" + td;
    return true;
  }
  else {
    td = "";
    return true;
  }
}

// #########################################################################
// Checks and corrects a time (number & unit) according Verilog standard.
bool Verilog_Time(QString& t, const QString& Name)
{
  char *p;
  double Time = strtod(t.latin1(), &p);
  double factor = 1.0;
  while(*p == ' ') p++;
  for(;;) {
    if(Time >= 0.0) {
      if(strcmp(p, "fs") == 0) { factor = 1e-3; break; }
      if(strcmp(p, "ps") == 0) { factor = 1;  break; }
      if(strcmp(p, "ns") == 0) { factor = 1e3;  break; }
      if(strcmp(p, "us") == 0) { factor = 1e6;  break; }
      if(strcmp(p, "ms") == 0) { factor = 1e9;  break; }
      if(strcmp(p, "sec") == 0) { factor = 1e12; break; }
      if(strcmp(p, "min") == 0) { factor = 1e12*60; break; }
      if(strcmp(p, "hr") == 0)  { factor = 1e12*60*60; break; }
    }
    t = QString::fromUtf8("§")  + QObject::tr("Error: Wrong time format in \"%1\". Use positive number with units").arg(Name)
            + " fs, ps, ns, us, ms, sec, min, hr.\n";
    return false;
  }

  t = QString::number(Time*factor);
  return true;
}

// #########################################################################
bool checkVersion(QString& Line)
{
  QStringList sl = QStringList::split('.',PACKAGE_VERSION);
  QStringList ll = QStringList::split('.',Line);
  if (ll.count() != 3 || sl.count() != 3)
    return false;
  int sv = (int)sl.at(1).toLongLong()*10000+sl.at(2).toLongLong()*100;
  int lv = (int)ll.at(1).toLongLong()*10000+ll.at(2).toLongLong()*100;
  if(lv > sv) // wrong version number ? (only backward compatible)
    return false;
  return true;
}
// #########################################################################
// ##########                                                     ##########
// ##########            MOVE SOMEWHERE ELSE END                  ##########
// ##########                                                     ##########
// #########################################################################

int doNetlist(QString schematic, QString netlist)
{
  qDebug() << "*** try to load schematic :" << schematic;

  QFile file(schematic);  // save simulator messages
  if(file.open(QIODevice::ReadOnly)) {
    file.close();
  }
  else {
    fprintf(stderr, "Error: Could not load schematic %s\n", schematic.ascii());
    return 1;
  }

  // populate Modules list
  Module::registerModules ();

  // new schematic from file
  Schematic *sch = new Schematic(0, schematic);

  // load schematic file if possible
  if(!sch->loadDocument()) {
    fprintf(stderr, "Error: Could not load schematic %s\n", schematic.ascii());
    delete sch;
    return 1;
  }

  qDebug() << "*** try to write netlist  :" << netlist;

  QStringList Collect;

  QTextEdit *ErrText = new QTextEdit();  //dummy
  QFile NetlistFile;
  QTextStream   Stream;

  Collect.clear();  // clear list for NodeSets, SPICE components etc.

  NetlistFile.setName(netlist);
  if(!NetlistFile.open(QIODevice::WriteOnly)) {
    fprintf(stderr, "Error: Could not load netlist %s\n", netlist.ascii());
    return -1;
  }

  Stream.setDevice(&NetlistFile);
  int SimPorts = sch->prepareNetlist(Stream, Collect, ErrText);

  if(SimPorts < -5) {
    NetlistFile.close();
    fprintf(stderr, "Error: Could not prepare the netlist...\n");
    return 1;
  }

  // output NodeSets, SPICE simulations etc.
  for(QStringList::Iterator it = Collect.begin();
  it != Collect.end(); ++it) {
    // don't put library includes into netlist...
    if ((*it).right(4) != ".lst" &&
    (*it).right(5) != ".vhdl" &&
    (*it).right(4) != ".vhd" &&
    (*it).right(2) != ".v") {
      Stream << *it << '\n';
    }
  }

  Stream << '\n';

  QString SimTime = sch->createNetlist(Stream, SimPorts);

  NetlistFile.close();

  return 0;
}


// #########################################################################
// ##########                                                     ##########
// ##########                  Program Start                      ##########
// ##########                                                     ##########
// #########################################################################
int main(int argc, char *argv[])
{
  // apply default settings
  SimguiSettings.font = QFont("Helvetica", 12);
  SimguiSettings.largeFontSize = 16.0;
  SimguiSettings.maxUndo = 20;
  SimguiSettings.NodeWiring = 0;

  // initially center the application
  QApplication a(argc, argv);
  QDesktopWidget *d = a.desktop();
  int w = d->width();
  int h = d->height();
  SimguiSettings.x = w/8;
  SimguiSettings.y = h/8;
  SimguiSettings.dx = w*3/4;
  SimguiSettings.dy = h*3/4;

  // check for relocation env variable
  char* var = getenv("SIMGUIDIR");
  QDir SimguiDir;
  if (var!= NULL)
  {
      SimguiDir = QDir(QString(var));
      qDebug() << "SIMGUIDIR set: " << SimguiDir.absolutePath();
  }
  else
  {
     QString SimguiApplicationPath = QCoreApplication::applicationDirPath();
     #ifdef __APPLE__
     SimguiDir = QDir(SimguiApplicationPath.section("/bin",0,0));
     #else
     SimguiDir = QDir(SimguiApplicationPath.replace("/bin",""));
     #endif

  }

  SimguiSettings.BinDir =      SimguiDir.absolutePath() + "/bin/";
  SimguiSettings.LangDir =     SimguiDir.canonicalPath() + "/share/simgui/lang/";
  SimguiSettings.LibDir =      SimguiDir.canonicalPath() + "/share/simgui/library/";
  SimguiSettings.OctaveDir =   SimguiDir.canonicalPath() + "/share/simgui/octave/";
  SimguiSettings.ExamplesDir = SimguiDir.canonicalPath() + "/share/simgui/docs/examples/";
  SimguiSettings.DocDir =      SimguiDir.canonicalPath() + "/share/simgui/docs/";

  SimguiSettings.Editor = "simgui";
  SimguiSettings.SimguiHomeDir.setPath(QDir::homeDirPath()+QDir::convertSeparators ("/.simgui"));
  SimguiSettings.SimguiWorkDir.setPath(SimguiSettings.SimguiHomeDir.canonicalPath());


  var = getenv("ADMSXMLBINDIR");
  if(var != NULL) {
      SimguiSettings.AdmsXmlBinDir.setPath(QString(var));
  }
  else {
      // default admsXml bindir same as Simgui
      QString admsExec;
#ifdef __MINGW32__
      admsExec = QDir::toNativeSeparators(SimguiSettings.BinDir+"/"+"admsXml.exe");
#else
      admsExec = QDir::toNativeSeparators(SimguiSettings.BinDir+"/"+"admsXml");
#endif
      QFile adms(admsExec);
      if(adms.exists())
        SimguiSettings.AdmsXmlBinDir.setPath(SimguiSettings.BinDir);
  }

  var = getenv("ASCOBINDIR");
  if(var != NULL)  {
      SimguiSettings.AscoBinDir.setPath(QString(var));
  }
  else  {
      // default ASCO bindir same as Simgui
      QString ascoExec;
#ifdef __MINGW32__
      ascoExec = QDir::toNativeSeparators(SimguiSettings.BinDir+"/"+"asco.exe");
#else
      ascoExec = QDir::toNativeSeparators(SimguiSettings.BinDir+"/"+"asco");
#endif
      QFile asco(ascoExec);
      if(asco.exists())
        SimguiSettings.AscoBinDir.setPath(SimguiSettings.BinDir);
  }

  var = getenv("OCTAVEBINDIR");
  if(var != NULL)  {
      SimguiSettings.OctaveBinDir.setPath(QString(var));
  }
  else  {
#ifdef __MINGW32__
      SimguiSettings.OctaveBinDir.setPath(QString("C:/Software/Octave-3.6.4/bin/"));
#else
      QFile octaveExec("/usr/bin/octave");
      if(octaveExec.exists())SimguiSettings.OctaveBinDir.setPath(QString("/usr/bin/"));
      QFile octaveExec1("/usr/local/bin/octave");
      if(octaveExec1.exists()) SimguiSettings.OctaveBinDir.setPath(QString("/usr/local/bin/"));
#endif
  }
  loadSettings();

  if(!SimguiSettings.BGColor.isValid())
    SimguiSettings.BGColor.setRgb(255, 250, 225);

  // syntax highlighting
  if(!SimguiSettings.Comment.isValid())
    SimguiSettings.Comment = Qt::gray;
  if(!SimguiSettings.String.isValid())
    SimguiSettings.String = Qt::red;
  if(!SimguiSettings.Integer.isValid())
    SimguiSettings.Integer = Qt::blue;
  if(!SimguiSettings.Real.isValid())
    SimguiSettings.Real = Qt::darkMagenta;
  if(!SimguiSettings.Character.isValid())
    SimguiSettings.Character = Qt::magenta;
  if(!SimguiSettings.Type.isValid())
    SimguiSettings.Type = Qt::darkRed;
  if(!SimguiSettings.Attribute.isValid())
    SimguiSettings.Attribute = Qt::darkCyan;
  if(!SimguiSettings.Directive.isValid())
    SimguiSettings.Directive = Qt::darkCyan;
  if(!SimguiSettings.Task.isValid())
    SimguiSettings.Task = Qt::darkRed;


  a.setFont(SimguiSettings.font);

  // set codecs
  QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
  QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

  QTranslator tor( 0 );
  QString lang = SimguiSettings.Language;
  if(lang.isEmpty())
    lang = QTextCodec::locale();
  tor.load( QString("simgui_") + lang, SimguiSettings.LangDir);
  a.installTranslator( &tor );

  // This seems to be neccessary on a few system to make strtod()
  // work properly !???!
  setlocale (LC_NUMERIC, "C");

  QString schematic;
  QString netlist;

  QString operation;

  // simple command line parser
  for (int i = 1; i < argc; ++i) {
    if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
      fprintf(stdout,
  "Usage: %s [OPTION]...\n\n"
  "  -h, --help     display this help and exit\n"
  "  -v, --version  display version information and exit\n"
  "  -n, --netlist  convert Simgui schematic into netlist\n"
  "  -i FILENAME    use file as input schematic\n"
  "  -o FILENAME    use file as output netlist\n"
  , argv[0]);
      return 0;
    }
    else if (!strcmp(argv[i], "-v") || !strcmp(argv[i], "--version")) {
      fprintf(stdout, "Simgui " PACKAGE_VERSION "\n");
      return 0;
    }
    else if (!strcmp(argv[i], "-n") || !strcmp(argv[i], "--netlist")) {
      operation = "netlist";
    }
    else if (!strcmp(argv[i], "-i")) {
      schematic = argv[++i];
    }
    else if (!strcmp(argv[i], "-o")) {
      netlist = argv[++i];
    }
    else {
      fprintf(stderr, "Error: Unknown option: %s\n", argv[i]);
      return -1;
    }
  }

  // check operation and its required arguments
  if (operation == "netlist") {
    if (schematic.isEmpty()) {
      fprintf(stderr, "Error: Expected input schematic file.\n");
      return -1;
    }
    if (netlist.isEmpty()) {
      fprintf(stderr, "Error: Expected output netlist file.\n");
      return -1;
    }
    // create netlist from schematic
    return doNetlist(schematic, netlist);
  }

  SimguiMain = new SimguiApp();
  a.setMainWidget(SimguiMain);
  qInstallMsgHandler(simguiMessageOutput);
  SimguiMain->show();
  int result = a.exec();
  //saveApplSettings(SimguiMain);
  return result;
}
