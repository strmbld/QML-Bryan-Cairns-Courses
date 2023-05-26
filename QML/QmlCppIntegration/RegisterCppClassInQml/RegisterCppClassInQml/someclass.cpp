#include "someclass.h"

SomeClass::SomeClass(QObject *parent)
    : QObject{parent}
{

}

void SomeClass::doWork(QVariant data)
{
    bool ok;
    int numIn = data.toInt(&ok);
    int numOut = 0;

    if(!ok) {
        qWarning() << "Not valid number!";

        emit status(QVariant(numOut));

        return;
    }

    int numRand = QRandomGenerator::global()->bounded(100);
    numOut = numIn * numRand;

    qInfo() << "In: " << numIn << '\n'
            << "Random: " << numRand << '\n'
            << "Out: " << numOut << '\n'
        ;

    emit status(QVariant(numOut));
}
