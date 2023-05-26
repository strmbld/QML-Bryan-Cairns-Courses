
#ifndef WIDGET_H
#define WIDGET_H


#include <QObject>
#include <QDebug>
#include <QTest>


class Widget : public QObject
{
private:
    Q_OBJECT

private slots:
    void testAge_data();
    void testAge();

public:
    explicit Widget(QObject *parent = nullptr);

signals:

};

#endif // WIDGET_H
