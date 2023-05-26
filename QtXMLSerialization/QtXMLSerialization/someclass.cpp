#include "someclass.h"


SomeClass::SomeClass(QObject *parent)
    : QObject{parent}
{

}


void SomeClass::fill()
{
    m_name = "test obj";

    for (int i = 0; i < 10; ++i) {
        QString num = QString::number(i);
        QString key = "Key" + num;
        QString value = "Value" + num;

        m_map.insert(key, value);
    }
}
