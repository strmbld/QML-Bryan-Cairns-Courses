
#include "widget.h"

Widget::Widget(QObject *parent)
    : QObject{parent}
{

}

void Widget::testAge_data()
{
    qInfo() << "Getting data for testAge()";

    QTest::addColumn<QString>("name");
    QTest::addColumn<int>("age");

    QTest::addRow("Invalid") << "Name1" << 190;
    QTest::addRow("Old") << "Name2" << 44;
    QTest::addRow("Young") << "Name3" << 25;
    QTest::addRow("Under age") << "Name4" << 14;
    QTest::addRow("Retired") << "Name5" << 90;

    qInfo() << "Data ready";
}

void Widget::testAge()
{
    QFETCH(QString, name);
    QFETCH(int, age);

    qInfo() << "Testing age " << name << " is " << age;

    if(age < 1 || age > 100) {
        QFAIL("Invalid age!");
    }

    if(age < 21) {
        QFAIL("Age is under 21!");
    }

    if(age > 40) {
        qWarning("Age is over 40!");
    }

    if(age > 65) {
        qInfo() << "Age is over 65!";
    }
}
