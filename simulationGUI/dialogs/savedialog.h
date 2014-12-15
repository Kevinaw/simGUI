
#ifndef SAVEDIALOG_H
#define SAVEDIALOG_H

#include <QVariant>
#include <QDialog>
#include <QMap>
#include <QBoxLayout>
#include <QGridLayout>
#include <QBoxLayout>
#include <QLabel>
#include <QCheckBox>

class QBoxLayout;
class QBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QListWidget;
class QListWidgetItem;
class QPushButton;
class SimguiDoc;
class SimguiApp;

class SaveDialog : public QDialog
{
   Q_OBJECT
   public:
      enum {
         AbortClosing = 0,
         DontSave,
         SaveSelected
      };
            
      SaveDialog(QWidget* p = 0, const char* n = 0, bool modal = true, Qt::WFlags fl = 0 );
      ~SaveDialog();
      void addUnsavedDoc(SimguiDoc *doc);
      void setApp(SimguiApp *a);
      bool isEmpty() const;
			     
   protected slots:
      void dontSaveClicked();
      void saveSelectedClicked();
      void reject();
      
   private:
      void initDialog();
      
      QMap<SimguiDoc*,QListWidgetItem*> unsavedDocs;
            
      QLabel* label;
      QListWidget* fileView;
      QPushButton* abortClosingButton;
      QPushButton* dontSaveButton;
      QPushButton* saveSelectedButton;
      QBoxLayout* SaveDialogLayout;
      QHBoxLayout* buttonsLayout;
      QSpacerItem* spacer;
      SimguiApp *app;
};

#endif // SAVEDIALOG_H
