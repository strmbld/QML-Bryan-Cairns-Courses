#include <QCoreApplication>
#include <QTest>

#include "cat.h"
#include "dog.h"
#include "widget.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cat cat;
    Dog dog;
    Widget widget;
    widget.setAge(999);
#ifdef QT_DEBUG
    int ret1 = QTest::qExec(&cat); // tests only parameter-less private slots by default

    qInfo() << ret1;

    int ret2 = QTest::qExec(&dog);

    qInfo() << ret2;

    int ret3 = QTest::qExec(&widget);

    qInfo() << ret3;
#endif
    return a.exec();
}
