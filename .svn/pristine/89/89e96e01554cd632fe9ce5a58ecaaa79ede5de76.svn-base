
#ifndef VACOMPONENT_H
#define VACOMPONENT_H

#include "component.h"

#include <QFile>
#include <QTextStream>
#include <QScriptEngine>
#include <QScriptValue>
#include <QScriptValueIterator>

#include <QDebug>

/*!
 * \file vacomponent.h
 * \brief Definition of the vacomponent class.
 */

class vacomponent : public Component
{
  public:
    vacomponent(QString filename);
    ~vacomponent() { };
    Component* newOne(QString filename);
    static Element* info(QString&, QString &,
                         bool getNewOne=false, QString filename="");
  protected:
    void createSymbol(QString filename);

};

//
QString getData(QString filename);
double getDouble(QScriptValue data, QString prop);
QString getString(QScriptValue data, QString prop);

#endif /* vacomponent_H */
