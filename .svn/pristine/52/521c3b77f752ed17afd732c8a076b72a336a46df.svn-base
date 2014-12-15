
#ifndef IMPORTDIALOG_H
#define IMPORTDIALOG_H

#include <QDialog>
#include <QProcess>
#include <QGridLayout>
#include <QLabel>

class QTextEdit;
class QLineEdit;
class QGridLayout;
class QPushButton;
class QComboBox;
class QLabel;


class ImportDialog : public QDialog  {
   Q_OBJECT
public:
  ImportDialog(QWidget*);
 ~ImportDialog();

private slots:
  void slotDisplayMsg();
  void slotDisplayErr();
  void slotProcessEnded(int status);
  void slotImport();
  void slotAbort();
  void slotBrowse();
  void slotType(int);

private:
  void startSimulator();

public:
  QGridLayout *all;

  QLabel *OutputLabel;
  QProcess Process;
  QTextEdit *MsgText;
  QLineEdit *ImportEdit, *OutputEdit, *OutputData;
  QPushButton *ImportButt, *CancelButt, *AbortButt;
  QComboBox *OutType;
};

#endif
