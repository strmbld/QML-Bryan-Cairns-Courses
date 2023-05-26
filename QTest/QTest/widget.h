
#ifndef WIDGET_H
#define WIDGET_H


#include <QObject>
#include <QDebug>
#include <QTest>


class Widget : public QObject
{
private:
    Q_OBJECT

    int m_age;

private slots:
    void testFail();
    void testAge();
    void testWidget();

public:
    explicit Widget(QObject *parent = nullptr);

    inline void setAge(int value) { m_age = value; }
signals:

};

#endif // WIDGET_H
