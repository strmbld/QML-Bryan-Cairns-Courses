
#include "dog.h"


Dog::Dog(QObject *parent)
    : QObject{parent}
{
    qInfo() << Q_FUNC_INFO;
}


void Dog::initTestCase()
{
    qInfo() << Q_FUNC_INFO;
}

void Dog::init()
{
    qInfo() << Q_FUNC_INFO;
}

void Dog::cleanup()
{
    qInfo() << Q_FUNC_INFO;
}

void Dog::cleanupTestCase()
{
    qInfo() << Q_FUNC_INFO;
}

void Dog::bark()
{
    qInfo() << Q_FUNC_INFO;
}

void Dog::rollover()
{
    qInfo() << Q_FUNC_INFO;
}
