
#ifndef GRAPHICTEXTDIALOG_H
#define GRAPHICTEXTDIALOG_H

#include <QDialog>
#include <QVBoxLayout>

class QLineEdit;
class QTextEdit;
class QPushButton;
class QVBoxLayout;
class QIntValidator;


class GraphicTextDialog : public QDialog  {
Q_OBJECT
public:
  GraphicTextDialog(QWidget *parent=0, const char *name=0);
 ~GraphicTextDialog();

private slots:
  void slotSetColor();
  void slotOkButton();

public:
  QLineEdit   *TextSize, *Angle;
  QPushButton *ColorButt;
  QTextEdit   *text;

private:
  QVBoxLayout *vert;
  QIntValidator *val50, *val360;
};

#endif
