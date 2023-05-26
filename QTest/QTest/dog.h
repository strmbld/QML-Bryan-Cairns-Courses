
#ifndef DOG_H
#define DOG_H


#include <QObject>
#include <QDebug>


class Dog : public QObject
{
private:
    Q_OBJECT

private slots:
    // before first test
    void initTestCase();
    // before each test
    void init();
    // after each test
    void cleanup();
    // after last test
    void cleanupTestCase();

    void bark();
    void rollover();

public:
    explicit Dog(QObject *parent = nullptr);

signals:

};

#endif // DOG_H
