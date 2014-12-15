
#ifndef SYNTAX_H
#define SYNTAX_H

#include <QtCore>
#include <QtGui>

#include "textdoc.h"
//#include "main.h"

enum language_type {
  LANG_NONE = 0,
  LANG_VHDL,
  LANG_VERILOG,
  LANG_VERILOGA,
  LANG_OCTAVE,
};

enum textstate_type {
  STATE_NONE = 0,
  STATE_COMMENT = 100,
};

class SyntaxHighlighter : public QSyntaxHighlighter {
public:
 SyntaxHighlighter(TextDoc*);
 virtual ~SyntaxHighlighter();

 void setLanguage(int);
 void highlightBlock(const QString&);

private:
  int language;
  TextDoc *Doc;

  struct HighlightingRule
     {
         QRegExp pattern;
         QTextCharFormat format;
     };
  
  QVector<HighlightingRule> highlightingRules;

  QTextCharFormat reservedWordFormat;
  QTextCharFormat unitFormat;
  QTextCharFormat datatypeFormat;
  QTextCharFormat directiveFormat;
  QTextCharFormat functionFormat;
  QTextCharFormat commentFormat;

};

#endif
