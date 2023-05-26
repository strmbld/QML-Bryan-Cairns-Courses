#ifndef SOMECLASS_H
#define SOMECLASS_H

#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QRandomGenerator>


class SomeClass : public QObject
{
    Q_OBJECT
public:
    explicit SomeClass(QObject *parent = nullptr);

public slots:
    void doWork(QVariant data);

signals:
    void status(QVariant data);
};

#endif // SOMECLASS_H
