#include <QCoreApplication>
#include <QDir>

#include "someclass.h"
#include "converter.h"


void write_json(QString path)
{
    SomeClass obj;
    obj.fill();
    Converter::write_JSON(&obj, path);
}

void read_json(QString path)
{
    SomeClass* obj;
    obj = Converter::read_JSON(path);

    if(!obj) {
        qDebug() << "Object not loaded";

        return;
    }

    qInfo() << "Name: " << obj->name();

    foreach (QString key, obj->map().keys()) {
        qInfo() << key << " : " << obj->map().value(key);
    }

    delete obj;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString prefix = QDir::currentPath() + QDir::separator();
    QString path = prefix + "json.txt";

    write_json(path);
    read_json(path);

    return a.exec();
}
