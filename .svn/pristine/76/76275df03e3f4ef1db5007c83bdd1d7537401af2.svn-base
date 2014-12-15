
#ifndef VERTICALTABBUTTON_H
#define VERTICALTABBUTTON_H

#include <QPushButton>
#include <QStyleOptionButton>
#include "vtabglobal.h"

/**
   This class provides vertical button which can be used as ordinary button
 
   @author Gopala Krishna A <krishna.ggk@gmail.com>
*/
class VTab : public QPushButton,public VTabInterface
{
  Q_OBJECT

public:
  VTab(VTabPosition pos = TabLeft,int p_id = -1,QWidget *parent=0l,const char* name=0l);
  VTabPosition position() const { return m_position; }
  int id() const;

  virtual QSize sizeHint() const;
  virtual void setText(const QString &s);

  virtual ~VTab();

public slots:
 void setID(int p_id);
 void setPosition(VTabPosition p_pos);

signals:
 void toggled(int p_id,bool p_state);// internal signal
protected:
  void paintEvent(QPaintEvent* event);
  
private:
  QStyleOptionButton getStyleOption() const;
 VTabPosition m_position;
 int m_id;

 virtual void drawButton(QPainter *p);
 void init();
	
private slots:
  void slotToggled(bool b);
};

/*inline VTabPosition VTab::position() const
{
    return m_position;
}*/

inline int VTab::id() const
{
  return m_id;
}

#endif
