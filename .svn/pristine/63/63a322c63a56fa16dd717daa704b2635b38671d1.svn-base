
#ifndef TEXTDOC_H
#define TEXTDOC_H

#include <QPlainTextEdit>
#include <QFont>

#include "simguidoc.h"

/*!
 * \file textdoc.h
 * \brief Definition of the TextDoc class.
 */

class SyntaxHighlighter;

extern const char *smallsave_xpm[];// icon for unsaved files (diskette)
extern const char *empty_xpm[];    // provides same height than "smallsave_xpm"

// device type flags
#define DEV_BJT      0x0001
#define DEV_MOS      0x0002
#define DEV_MASK_DEV 0x00FF
#define DEV_DIG      0x0100
#define DEV_ANA      0x0200
#define DEV_ALL      0x0300
#define DEV_MASK_TYP 0xFF00
#define DEV_DEF      0x0200 // default value

/*!
 * \brief The TextDoc class definition
 */
class TextDoc : public QPlainTextEdit, public SimguiDoc {
  Q_OBJECT
public:
  TextDoc (SimguiApp *, const QString&);
 ~TextDoc ();

  void  setName (const QString&);
  bool  load ();
  int   save ();
  float zoomBy (float);
  void  showNoZoom ();
  void  becomeCurrent (bool);
  bool  loadSimulationTime (QString&);
  void  commentSelected ();
  void  insertSkeleton ();
  void  setLanguage (int);
  void  setLanguage (const QString&);
  QString getModuleName (void);


  QFont TextFont;

  bool simulation;   // simulation or module
  QString Library;   // library this document belongs to
  QString Libraries; // libraries to be linked with
  QString ShortDesc; // icon description
  QString LongDesc;  // component description
  QString Icon;      // icon file
  bool recreate;     // recreate output file
  int devtype;       // device type

  bool SetChanged;
  int language;

  bool loadSettings (void);
  bool saveSettings (void);
  void refreshLanguage(void);

  QMenu* createStandardContextMenu(const QPoint&);

public slots:
  void slotCursorPosChanged ();
  void slotSetChanged ();

private:
  SyntaxHighlighter * syntaxHighlight;

private slots:
   void highlightCurrentLine();
};

#endif
