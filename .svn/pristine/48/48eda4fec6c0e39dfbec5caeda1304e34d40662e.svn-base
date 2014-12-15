//Added by qt3to4:
#include <Q3PtrList>
#include <Q3Dict>
#include <QMap>

#ifndef MODULE_H
#define MODULE_H

// function typedefs for circuits and analyses
typedef Element * (* pInfoFunc) (QString&, char * &, bool);
typedef Element * (* pInfoVAFunc) (QString&, QString&, bool, QString);
typedef Component * (* pCreatorFunc) ();

class Module
{
 public:
  Module ();
  ~Module ();
  static void registerModule (QString, pInfoFunc);
  static void registerComponent (QString, pInfoFunc);
  static void intoCategory (Module *);
  static Component * getComponent (QString);
  static void registerDynamicComponents(void);

 public:
  static Q3Dict<Module> Modules;
  static QMap<QString, QString> vaComponents;

 public:
  static void registerModules (void);
  static void unregisterModules (void);

 public:
  pInfoFunc info;
  pInfoVAFunc infoVA;
  QString category;
};

class Category
{
 public:
  Category ();
  Category (const QString);
  ~Category ();

 public:
  static Q3PtrList<Category> Categories;

 public:
  static QStringList getCategories (void);
  static Q3PtrList<Module> getModules (QString);
  static int getModulesNr (QString);

 public:
  QString Name;
  Q3PtrList<Module> Content;
};

#endif /* __MODULE_H__ */
