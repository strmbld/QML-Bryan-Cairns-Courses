#include "converter.h"


Converter::Converter(QObject *parent)
    : QObject{parent}
{

}


void Converter::write_JSON(SomeClass *obj, QString path)
{
    QVariantMap map;
    QVariantMap items;

    map["name"] = obj->name();

    foreach (QString key, obj->map().keys()) {
        items.insert(key, QVariant(obj->map().value(key)));
    }

    map["items"] = QVariant(items);

    QJsonDocument doc = QJsonDocument::fromVariant(map);

    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) {
        qCritical() << "Unable to write file! " << file.errorString();

        return;
    }

    file.write(doc.toJson());
    file.close();
}

SomeClass *Converter::read_JSON(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Unable to read file! " << file.errorString();

        return nullptr;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    SomeClass* obj = new SomeClass();
    obj->set_name(doc["name"].toString());
    QVariantMap vmap = qvariant_cast<QVariantMap>(doc["items"]);

    QMap<QString, QString> map;

    foreach (QString key, vmap.keys()) {
        map.insert(key, vmap[key].toString());
    }

    obj->set_map(map);

    return obj;
}
