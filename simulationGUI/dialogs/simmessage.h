
#ifndef SIMMESSAGE_H
#define SIMMESSAGE_H

#include <QDialog>
#include <QProcess>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>

class QTextEdit;
class QTextStream;
class QVBoxLayout;
class QPushButton;
class QProgressBar;
class QProcess;
class QFile;
class Component;
class Schematic;

// #define SPEEDUP_PROGRESSBAR


class SimMessage : public QDialog  {
Q_OBJECT
public:
  SimMessage(QWidget*, QWidget *parent=0);
 ~SimMessage();

  bool startProcess();

signals:
  void SimulationEnded(int, SimMessage*);
  void displayDataPage(QString&, QString&);

public slots:
  void slotClose();

private slots:
  void slotDisplayMsg();
  void slotDisplayErr();
  void slotCloseStdin();
  void slotSimEnded(int status);
  void slotDisplayButton();
  void AbortSim();

  void slotReadSpiceNetlist();
  void slotFinishSpiceNetlist(int status);

/* #ifdef SPEEDUP_PROGRESSBAR
  void slotUpdateProgressBar();
private:
  int  iProgress;
  bool waitForUpdate;
#endif
*/

private:
  void FinishSimulation(int);
  void nextSPICE();
  void startSimulator();
  Component * findOptimization(Schematic *);

public:
  QWidget *DocWidget;
  int showBias;
  bool SimOpenDpl;
  bool SimRunScript;
  QString DocName, DataSet, DataDisplay, Script;

  QProcess      SimProcess;
  QTextEdit    *ProgText, *ErrText;
  bool          wasLF;   // linefeed for "ProgText"
  QPushButton  *Display, *Abort;
  QProgressBar *SimProgress;
  QString       ProgressText;

  Component    *SimOpt;
  int           SimPorts;
  bool          makeSubcircuit, insertSim;
  QStringList   Collect;
  QFile         NetlistFile;
  QTextStream   Stream;

  QVBoxLayout  *all;
};

#endif
