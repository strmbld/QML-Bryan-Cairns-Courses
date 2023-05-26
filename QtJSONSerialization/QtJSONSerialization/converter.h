#ifndef CONVERTER_H
#define CONVERTER_H


#include <QObject>
#include <QVariantMap>
#include <QJsonDocument>
#include <QFile>

#include "someclass.h"


class Converter : public QObject
{
private:
    Q_OBJECT

public:
    explicit Converter(QObject *parent = nullptr);


    static void write_JSON(SomeClass* obj, QString path);
    static SomeClass* read_JSON(QString path);
};

#endif // CONVERTER_H
