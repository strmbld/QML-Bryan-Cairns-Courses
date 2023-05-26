#ifndef SOMEPLUGIN_H
#define SOMEPLUGIN_H


#include <QObject>
#include <QtPlugin>
#include <QDebug>
#include <QString>

#include "plugin.h"


class SomePlugin : public QObject, public Plugin
{
private:
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "company_name_plugin")
    Q_INTERFACES(Plugin)

public:
    explicit SomePlugin(QObject* parent = nullptr);
    ~SomePlugin();
    // Plugin interface
    void test(QString name) override;

};


#endif // SOMEPLUGIN_H
