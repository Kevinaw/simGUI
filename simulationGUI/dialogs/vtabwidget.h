
#ifndef VERTICALTABWIDGET_H
#define VERTICALTABWIDGET_H

#include "vtabglobal.h"
#include <QWidget>

class Q3WidgetStack;
class VTabBar;

/**
    @author Gopala Krishna A <krishna.ggk@gmail.com>
*/
class VTabWidget : public QWidget,public VTabInterface
{
  Q_OBJECT
public:
  VTabWidget(VTabPosition p = TabLeft,QWidget* parent=0l, const char* name=0l);

  virtual ~VTabWidget();
  virtual QSize sizeHint() const;
  void addPage(QWidget *w,const QString& tabCap);
	
  QWidget* page(int id);
  QWidget* currentPage();
  void setTabToolTip(int id,const QString &tip);
  void removePage(QWidget *w);
  void removePage(int id);
  int id(QWidget *w);

public slots:
  void setPosition(VTabPosition p);
  void setCurrentPage(int id);
  void setCurrentPage(QWidget *w);
	
signals:
  void widgetStackShown();
  void widgetStackHidden();
  void activatedPage(QWidget *w);

private:
  VTabPosition m_position;
  VTabBar* m_bar;
  Q3WidgetStack* m_wStack;
  int m_autoIndexer;

};

#endif
