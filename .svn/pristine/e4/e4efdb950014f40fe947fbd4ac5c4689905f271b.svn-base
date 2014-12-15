
#ifndef VTABBEDDOCKWIDGET_H
#define VTABBEDDOCKWIDGET_H

#include "vtabglobal.h"
#include <Q3DockWindow>

class VTabWidget;

/**
    @author Gopala Krishna A <krishna.ggk@gmail.com>
*/
class VTabbedDockWidget : public Q3DockWindow,public VTabInterface
{
  Q_OBJECT
public:
  VTabbedDockWidget(Place p=InDock, QWidget* parent=0l, const char* name=0l);

  virtual ~VTabbedDockWidget();

  virtual void setWidget(QWidget *w);
private:
  VTabWidget *m_tabWidget;

private slots:
  void slotStackShown();
  void slotStackHidden();
  void updatePosition(Q3DockWindow::Place p);
};

#endif
