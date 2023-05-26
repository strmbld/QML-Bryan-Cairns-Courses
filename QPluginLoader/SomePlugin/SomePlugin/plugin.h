
#ifndef PLUGIN_H
#define PLUGIN_H

#include <QString>
#include <QDebug>

class Plugin
{
public:
    // virtual ~Plugin() = 0;
    virtual void test(QString name) = 0;
};

Q_DECLARE_INTERFACE(Plugin, "company_name_plugin")

#endif // PLUGIN_H
