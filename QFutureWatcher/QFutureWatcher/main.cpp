#include <QCoreApplication>
#include <QFutureWatcher>
#include <QtConcurrent>

#include "someclass.h"


int multiply(const int& value)
{
    qInfo() << "multiply() on : " << value;

    return value * 10;
}

void mult(int &value)
{
    qInfo() << "mult() on : " << value;

    value *= 10;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    for (int i = 0; i < 100; ++i) {
        list.append(i);
    }

    QFutureWatcher<void> watcher;
    SomeClass object;
    QObject::connect(&watcher, &QFutureWatcher<void>::finished, &object, &SomeClass::finished, Qt::QueuedConnection);

    QFuture<void> future = QtConcurrent::map(list, &mult);
    watcher.setFuture(future);

    qInfo() << "Back in main()";

    watcher.waitForFinished();

    qInfo() << "Done!";
    qInfo() << list;

    //////////

    QFutureWatcher<int> w;
    QFuture<int> f = QtConcurrent::mapped(list, &multiply);

    w.setFuture(f);
    w.waitForFinished();
    //f.waitForFinished();

    // after &QFutureWatcher::finished can do some signals/slots stuff
    // also QFutureWatcher has other signals/slots could be used to do something while it is working

    // qInfo() << w.result();
    // qInfo() << w.resultAt(0);
    qInfo() << f.results();

    QFutureIterator<int> it(f);
    while (it.hasNext()) {
        qInfo() << it.next();
    }

    for (int i = 0; i < f.results().count(); ++i) {
        qInfo() << f.resultAt(i);
    }

    foreach (int i, f.results()) {
        qInfo() << i;
    }

    QList<int> values = f.results();
    for (auto i = values.begin(); i < values.end(); ++i) {
        qInfo() << *i;
    }

    for (auto i = values.begin(); i != values.end(); ++i) {
        qInfo() << *i;
    }

    return a.exec();
}
