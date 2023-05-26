#include "someclass.h"

SomeClass::SomeClass(QObject *parent)
    : QObject{parent}
{

}

int SomeClass::getNumber()
{
    qDebug() << Q_FUNC_INFO;

    return 42;
}

void SomeClass::doSomething()
{
    qDebug() << Q_FUNC_INFO;
}
