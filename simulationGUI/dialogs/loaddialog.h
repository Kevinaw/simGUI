
#ifndef LOADDIALOG_H
#define LOADDIALOG_H

#include <QVariant>
#include <QDialog>
#include <QMap>
#include <QBoxLayout>
#include <QGridLayout>
#include <QBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QDir>

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

class LoadDialog : public QDialog
{
    Q_OBJECT
public:

    enum {
        AbortClosing = 0,
        DontSave,
        Accept
    };

    LoadDialog(QWidget* p = 0, const char* n = 0, bool modal = true, Qt::WFlags fl = 0 );
    ~LoadDialog();
    void setApp(SimguiApp *a);
    void initDialog();

    QStringList symbolFiles;
    QDir projDir;

    QMap<QString, QString> selectedComponents;

private slots:
    void slotSelectAll();
    void slotSelectNone();
    void slotSymbolFileClicked(QListWidgetItem *item);

protected slots:
    void reject();
    void loadSelected();
    void slotChangeIcon();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private:
    QLabel *iconPixmap;
    QLabel* label;
    QListWidget* fileView;
    QBoxLayout* LoadDialogLayout;
    QHBoxLayout* buttonsLayout;
    QSpacerItem* spacer;
    SimguiApp *app;

    QPushButton *ButtOk, *ButtCancel,
                *ButtSelectAll, *ButtSelectNone,
                *ButtChangeIcon;
};

#endif // LOADDIALOG_H
