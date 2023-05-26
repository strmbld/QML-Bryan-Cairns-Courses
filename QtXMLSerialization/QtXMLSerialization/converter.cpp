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

void Converter::write_Xml(SomeClass *obj, QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) {
        qCritical() << "Unable to write file! " << file.errorString();

        return;
    }

    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();

    stream.writeStartElement("SomeClass");
    stream.writeAttribute("name", obj->name());

    stream.writeStartElement("items");

    foreach (QString key, obj->map().keys()) {
        stream.writeStartElement("item");
        stream.writeAttribute("key", key);
        stream.writeAttribute("value", obj->map().value(key));
        stream.writeEndElement();
    }

    stream.writeEndElement();
    stream.writeEndElement();

    stream.writeEndDocument();

    file.close();
}

SomeClass *Converter::read_Xml(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Unable to read file! " << file.errorString();

        return nullptr;
    }

    QByteArray data = file.readAll();
    file.close();

    QXmlStreamReader stream(data);
    SomeClass* obj = new SomeClass();
    QMap<QString, QString> map;

    while (!stream.atEnd()) {
        QXmlStreamReader::TokenType token = stream.readNext();
        switch (token) {
        case QXmlStreamReader::Comment:
            break;
        case QXmlStreamReader::DTD:
            break;
        case QXmlStreamReader::Characters:
            break;
        case QXmlStreamReader::ProcessingInstruction:
            break;
        case QXmlStreamReader::EntityReference:
            break;
        case QXmlStreamReader::NoToken:
            break;
        case QXmlStreamReader::Invalid:
            break;
        case QXmlStreamReader::StartDocument:
            break;
        case QXmlStreamReader::EndDocument:
            obj->set_map(map);
            break;
        case QXmlStreamReader::StartElement:
            if(stream.name().toString() == "SomeClass") {
                QString name = stream.attributes().value("name").toString();
                obj->set_name(name);
            }

            if(stream.name().toString() == "item") {
                QString key = stream.attributes().value("key").toString();
                QString value = stream.attributes().value("value").toString();

                map.insert(key, value);
            }

            break;
        case QXmlStreamReader::EndElement:
            break;
        }

    }

    return obj;
}
