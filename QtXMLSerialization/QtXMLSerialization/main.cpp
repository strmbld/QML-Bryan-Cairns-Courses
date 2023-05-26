#include <QCoreApplication>
#include <QDir>

#include "someclass.h"
#include "converter.h"


void write_XML(QString path)
{
    SomeClass obj;
    obj.fill();
    Converter::write_Xml(&obj, path);
}

void read_XML(QString path)
{
    SomeClass* obj;
    obj = Converter::read_Xml(path);

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
    QString path = prefix + "xml.txt";

    write_XML(path);
    read_XML(path);

    return a.exec();
}
