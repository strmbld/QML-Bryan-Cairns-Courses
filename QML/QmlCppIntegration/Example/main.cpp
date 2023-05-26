#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "worker.h"


int main(int argc, char *argv[])
{
    qmlRegisterType<Worker>("com.application.worker", 1, 0, "Worker");

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/Example/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
