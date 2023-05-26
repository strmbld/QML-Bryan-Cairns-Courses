#ifndef SOMECLASS_H
#define SOMECLASS_H

#include <QObject>
#include <QDebug>


class SomeClass : public QObject
{
    Q_OBJECT
public:
    explicit SomeClass(QObject *parent = nullptr);


    int getNumber();

public slots:
    void doSomething();

signals:

};

#endif // SOMECLASS_H
