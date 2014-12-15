
#ifndef VERTICALTABBAR_H
#define VERTICALTABBAR_H

#include "vtabglobal.h"
#include "vtabbutton.h"
#include <QWidget>
#include <Q3PtrList>
//Added by qt3to4:
#include <Q3VBoxLayout>

class Q3VBoxLayout;
class VTab;

/**
    @author Gopala Krishna A <krishna.ggk@gmail.com>
*/
class VTabBar : public QWidget,public VTabInterface
{
  Q_OBJECT
public:
  VTabBar(VTabPosition p = TabLeft,QWidget* parent = 0l, const char* name = 0l);

  virtual ~VTabBar();
  VTab* addTab(const QString& caption,int id = -1);

  VTab* findTab(int id);
  void setTabToolTip(VTab *tab,const QString &tip);
  void setTabToolTip(int id,const QString &tip);
  void removeTab(VTab *tab);
  void removeTab(int id);
  bool isAllTabsOff();

public slots:

  void setCurrentTab(VTab *tab);
  void setCurrentTab(int id);
  void setPosition(VTabPosition p_pos);
  void switchOffAllTabs();

signals:
  void activatedTab(int p_id);
  void activatedTab(VTab *tab);
  void allTabsOff();

private slots:
  void setTabState(int p_id,bool state);

private:
 int m_index;
 bool m_tabsOff;
 VTabPosition m_position;
 Q3VBoxLayout* m_layout;
 Q3PtrList<VTab> m_tabs;

};

#endif
