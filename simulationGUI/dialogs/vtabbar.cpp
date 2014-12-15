
#include "vtabbutton.h"
#include "vtabbar.h"

#include <QLayout>
#include <QToolTip>
//Added by qt3to4:
#include <Q3VBoxLayout>

VTabBar::VTabBar(VTabPosition p,QWidget* parent, const char* name): QWidget(parent, name)
{
  m_position = p;
  m_layout = new Q3VBoxLayout(this);
  m_layout->addStretch(800); //HACK to avoid spaces b/w buttons
  m_index = 0;
  m_tabsOff = true;
  m_tabs.setAutoDelete( false );
  setSizePolicy( QSizePolicy::Fixed,QSizePolicy::MinimumExpanding);
}

VTabBar::~VTabBar()
{}

VTab* VTabBar::addTab(const QString& caption,int id)
{
  VTab *tab = new VTab(m_position,id,this);
  tab->setText(caption);
  m_layout->insertWidget(m_index,tab);
  m_tabs.append(tab);
  m_index++;
  connect(tab,SIGNAL(toggled(int, bool )),this,SLOT(setTabState(int, bool )));
  updateGeometry();
  return tab;
}

VTab* VTabBar::findTab(int _id)
{
  VTab * c = m_tabs.first();
  for ( ; c; c = m_tabs.next() )
    {
      if(c->id() == _id)
	return c;
    }
  return 0l;
}

void VTabBar::setTabToolTip(VTab *tab,const QString &tip)
{
  QToolTip::add(tab,tip);
}

void VTabBar::setTabToolTip(int id,const QString &tip)
{
  VTab *tab = findTab(id);
  if(tab)
    QToolTip::add(tab,tip);
}

void VTabBar::removeTab(VTab *tab)
{
  VTab * c = m_tabs.first();
  for ( ; c; c = m_tabs.next() )
    {
      if(c == tab)
	{
	  m_tabs.remove(c);
	  return;
	}
    }
}
#include <iostream>
using namespace std;
void VTabBar::removeTab(int _id)
{
  VTab * c = m_tabs.first();
  for ( ; c; c = m_tabs.next() )
    {
		cout<<c->id()<<endl;
      if(c->id() == _id)
	{
	  m_tabs.remove(c);
	  return;
	}
    }
}

void VTabBar::setCurrentTab(VTab *tab)
{
  setTabState(tab->id(),true);
}

void VTabBar::setCurrentTab(int id)
{
  setTabState(id,true);
}

void VTabBar::setTabState(int p_id,bool state)
{
  VTab *c,*current;
  c = current = 0l;
  for ( c = m_tabs.first(); c; c = m_tabs.next() )
    {
      c->blockSignals(true);
      if(c->id() == p_id && state == true)
	{
	  current = c;
	  current->setOn(true);
	}
      else
	c->setOn(false);
      c->blockSignals(false);
    }
  if(current)
    {
      emit activatedTab( p_id);
      emit activatedTab(current);
      m_tabsOff = false;
    }
  else
    {
      m_tabsOff = true;
      emit allTabsOff();
    }
}

bool VTabBar::isAllTabsOff()
{
  return m_tabsOff;
}

void VTabBar::switchOffAllTabs()
{
  VTab *c = m_tabs.first();
  for ( ; c; c = m_tabs.next() )
    {
      c->blockSignals(true);
      c->setOn(false);
      c->blockSignals(false);
    }
  m_tabsOff = true;
  emit allTabsOff();
}

void VTabBar::setPosition(VTabPosition p_pos)
{
  if(m_position == p_pos)
    return;
  m_position = p_pos;
  VTab * c = m_tabs.first();
  while(c)
    {
      c->setPosition(m_position);
      c = m_tabs.next();
    }
}
