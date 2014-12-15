
#ifndef MESSAGEDOCK_H
#define MESSAGEDOCK_H

#include "simgui.h"

#include <QWidget>

#include <QDockWidget>
#include <QTabWidget>

/*!
 * \file messagedock.h
 * \brief The MessageDock class definiion
 */
class MessageDock : public QWidget {
  Q_OBJECT
public:
  MessageDock(SimguiApp*);
 ~MessageDock() {};

public:

  QDockWidget *msgDock;

  QTabWidget *builderTabs;

  /*!
   * \brief admsOutput holds the make output of running admsXml
   */
  QPlainTextEdit *admsOutput;
  /*!
   * \brief cppOutput holds the make output of running a C++ compiler
   */
  QPlainTextEdit *cppOutput;

  void reset();


private slots:
  void slotAdmsChanged();
  void slotCppChanged();
  void slotCursor();

};

#endif // MESSAGEDOCK_H
