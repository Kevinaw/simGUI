
#ifndef SPICEFILE_H
#define SPICEFILE_H
#include <QtGui>
#include "component.h"

#include <QObject>
#include <QDateTime>
//Added by qt3to4:
#include <QTextStream>

class QProcess;
class QTextStream;
class QString;

class SpiceFile : public QObject, public MultiViewComponent  {
   Q_OBJECT
public:
  SpiceFile();
 ~SpiceFile() {};
  Component* newOne();
  static Element* info(QString&, char* &, bool getNewOne=false);

  bool withSim;
  bool createSubNetlist(QTextStream *);
  QString getErrorText() { return ErrText; }
  QString getSubcircuitFile();

private:
  bool makeSubcircuit;
  bool insertSim;
  bool changed;
  QProcess *SimguiConv, *SpicePrep;
  QString NetText, ErrText, NetLine, SimText;
  QTextStream *outstream, *filstream, *prestream;
  QDateTime lastLoaded;
  bool recreateSubNetlist(QString *, QString *);

protected:
  QString netlist();
  void createSymbol();

private slots:
  void slotGetNetlist();
  void slotGetError();
  void slotExited();
  void slotSkipOut();
  void slotSkipErr();
  void slotGetPrepOut();
  void slotGetPrepErr();
};

#endif
