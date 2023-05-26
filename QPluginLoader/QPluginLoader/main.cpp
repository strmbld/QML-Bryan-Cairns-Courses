#include <QCoreApplication>
#include <QString>
#include <QPluginLoader>
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>

#include "plugin.h"


QStringList getPlugins(QString path)
{
    QStringList plugins;

    QStringList filter;
    filter << "*.dll" << "*.so" << "*.dylib";

    QDir dir(path);
    QFileInfoList list = dir.entryInfoList(filter);
    foreach (QFileInfo file, list) {
        plugins.append(file.filePath());
        // Mac - if(!file.isSymLink()) plugins.append(file.filepath());
    }

    return plugins;
}

void testPlugins(QStringList plugins)
{
    foreach (QString file, plugins) {
        qInfo() << "Loading..." << file;

        QPluginLoader loader(file);
        if(!loader.load()) {
            qInfo() << "Error: " << loader.fileName() << " Error: " << loader.errorString();

            continue;
        }

        qInfo() << "Loaded: " << loader.fileName();
        Plugin* plugin = qobject_cast<Plugin*>(loader.instance());
        if(plugin) {
            plugin->test("TEST");
            loader.unload(); // sometimes fails
        } else {
            qInfo() << "Could not cast: " << loader.fileName();
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir = QDir::current();
    dir.cd("plugins");

    qInfo() << "Path: " << dir.path();

    QStringList plugins = getPlugins(dir.path());
    qInfo() << "Plugins: " << plugins;

    testPlugins(plugins);

    return a.exec();
}
