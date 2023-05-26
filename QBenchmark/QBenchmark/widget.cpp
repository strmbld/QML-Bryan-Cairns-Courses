
#include "widget.h"


Widget::Widget(QObject *parent)
    : QObject{parent}
{

}


void Widget::testFor()
{
    QList<int> list;
    list.fill(0, 100);

    QBENCHMARK
    {
        for (int i = 0; i < list.count(); ++i) {

        }
    }
}

void Widget::testForeach()
{
    QList<int> list;
    list.fill(0, 100);

    QBENCHMARK
    {
        foreach (int value, list) {

        }
    }
}

void Widget::testString()
{
    QString string1 = "string1";
    QString string2 = "string2";

    QBENCHMARK
    {
        int ret = string1.compare(string2);
    }
}

void Widget::testComp()
{
    QString string1 = "string1";
    QString string2 = "string2";

    QBENCHMARK
    {
        QCOMPARE(string1, string2);
    }
}
