
#ifndef WIDGET_H
#define WIDGET_H


#include <QObject>
#include <QTest>

class Widget : public QObject
{
    Q_OBJECT

private slots:
    void testFor();
    void testForeach();
    void testString();
    void testComp();

public:
    explicit Widget(QObject *parent = nullptr);

signals:

};

#endif // WIDGET_H
