#include "widget.h"


Widget::Widget(QObject *parent)
    : QObject{parent}
    , m_age(0)
{

}


void Widget::testFail()
{
    QFAIL("FAIL");
}

void Widget::testAge()
{
    if(!m_age) {
        QFAIL("Age is not set!");
    }
}

void Widget::testWidget()
{
    int value = 45;

    QVERIFY(m_age > 0 && m_age < 100);

    if(m_age > 40) {
        qWarning("Age is over 40!");
    }

    if(m_age < 21) {
        QFAIL("Age is under 21!");
    }

    QCOMPARE(m_age, value);
}
