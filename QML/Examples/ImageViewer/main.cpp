#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "dirhelper.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<DirHelper>("com.application.dirhelper", 1, 0, "DirHelper");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/ImageViewer/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
