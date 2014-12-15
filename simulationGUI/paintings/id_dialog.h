
#ifndef ID_DIALOG_H
#define ID_DIALOG_H

#include <QDialog>
#include <QRegExp>
//Added by qt3to4:
#include <Q3VBoxLayout>


class ID_Text;
class Q3ListView;
class QLineEdit;
class QCheckBox;
class Q3VBoxLayout;
class Q3ListViewItem;
class QRegExpValidator;


class ID_Dialog : public QDialog  {
Q_OBJECT
public:
  ID_Dialog(ID_Text*);
 ~ID_Dialog();

private:
  ID_Text *idText;

  Q3VBoxLayout *v;
  QLineEdit *Prefix;

  Q3ListView *ParamList;
  QCheckBox *showCheck;
  QLineEdit *ParamNameEdit, *ValueEdit, *DescriptionEdit, *TypeEdit;

  QRegExp Expr;
  QRegExpValidator *SubVal, *NameVal, *ValueVal, *DescrVal, *TypeVal;

private slots:
  void slotOk();
  void slotAddParameter();
  void slotRemoveParameter();
  void slotEditParameter(Q3ListViewItem*);
  void slotToggleShow(bool);
  void slotNameChanged(const QString&);
  void slotValueChanged(const QString&);
  void slotDescrChanged(const QString&);
  void slotTypeChanged(const QString&);
};

#endif
