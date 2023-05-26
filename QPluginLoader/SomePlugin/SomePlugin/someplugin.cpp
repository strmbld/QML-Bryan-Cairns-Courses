#include "someplugin.h"


SomePlugin::SomePlugin(QObject *parent)
{
    Q_UNUSED(parent);
    qInfo() << "Plugin Constructed";
}

SomePlugin::~SomePlugin()
{
    qInfo() << "Plugin Deconstructed";
}


void SomePlugin::test(QString name)
{
    qInfo() << "SomePlugin.test(name): " << name;
}
