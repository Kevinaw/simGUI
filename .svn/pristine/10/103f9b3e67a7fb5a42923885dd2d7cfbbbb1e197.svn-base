
#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>

class SimguiApp;
class QLineEdit;
class QCheckBox;
class QGroupBox;
class QPushButton;


class SearchDialog : public QDialog  {
Q_OBJECT
public:
  SearchDialog(SimguiApp*);
 ~SearchDialog();

  void initSearch(bool replace=false);
  void searchText(bool, int);

private slots:
  void slotSearch();

private:
  SimguiApp *App;
  QLineEdit *SearchEdit, *ReplaceEdit;
  QCheckBox *PositionBox, *CaseBox, *WordBox, *BackwardBox, *AskBox;
  QGroupBox *ReplaceGroup;
};

#endif
