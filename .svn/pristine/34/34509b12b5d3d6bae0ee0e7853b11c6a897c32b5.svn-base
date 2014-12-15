
#ifndef PACKAGEDIALOG_H
#define PACKAGEDIALOG_H

#include <QFile>
#include <QDialog>
#include <QList>
#include <QStringList>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QDir>

class SimguiApp;
class QString;
class QLineEdit;
class QTextEdit;
class QCheckBox;
class QVBoxLayout;
class QDataStream;
class QPushButton;
class QGroupBox;


class PackageDialog : public QDialog {
   Q_OBJECT
public:
  PackageDialog(QWidget*, bool);
 ~PackageDialog();

  void extractPackage();

private slots:
  void slotCreate();
  void slotBrowse();

private:
  int insertFile(const QString&, QFile&, QDataStream&);
  int insertDirectory(const QString&, QDataStream&);
  int insertLibraries(QDataStream&);

  int extractFile(QFile&, Q_UINT32, QDir&);
  int extractDirectory(QFile&, Q_UINT32, QDir&);
  int extractLibrary(QFile&, Q_UINT32);

  QVBoxLayout *all;   // the mother of all widgets
  QLineEdit *NameEdit;
  QTextEdit *MsgText;
  QCheckBox *LibraryCheck;
  QGroupBox *Group;
  QList<QCheckBox *> BoxList;
  QPushButton *ButtClose;
};

#endif
