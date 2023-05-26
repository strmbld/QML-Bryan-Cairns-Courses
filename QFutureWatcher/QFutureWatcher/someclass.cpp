#include "someclass.h"


SomeClass::SomeClass(QObject *parent)
    : QObject{parent}
{

}


void SomeClass::finished()
{
    qInfo() << this << "Processing...";
}
