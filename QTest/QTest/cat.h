
#ifndef CAT_H
#define CAT_H


#include <QObject>
#include <QDebug>


class Cat : public QObject
{
private:
    Q_OBJECT

    void private_test();

private slots:
    void meow();
    void sleep();
    void speak(QString value);

public:
    explicit Cat(QObject *parent = nullptr);

    void public_test();
    void play();

public slots:
    void test();

signals:

};

#endif // CAT_H
