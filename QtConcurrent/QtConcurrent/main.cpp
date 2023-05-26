#include <QCoreApplication>
#include <QtConcurrent>
#include <QThread>
#include <QThreadPool>


void with_future_result(QString name, int max)
{
    for (int i = 0; i < max; ++i) {
        qInfo() << name << " " << i << QThread::currentThread();
    }
}

void loop()
{
    for (int i = 0; i < 10; ++i) {
        qInfo() << "Loop" << i << " on " << QThread::currentThread();
    }
}

void test()
{
    qInfo() << "Test on: " << QThread::currentThread();

    loop();
}

int do_map(int value)
{
    qInfo() << "Do stuff: " << value;
    int num = value * 10;

    return num;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> values;

    for (int i = 0; i < 9; ++i) {
        values << i;
    }

    qInfo() << "Starting ...";

    QList<int> updated = QtConcurrent::blockingMapped(values, &do_map);

    qInfo() << "Finished!";
    qInfo() << updated;

    ////////////////////////

    QThread::currentThread()->setObjectName("Main Thread");

    QThreadPool pool;
    QFuture<void> future = QtConcurrent::run(&pool, test);
    qInfo() << "Main on: " << QThread::currentThread();

    // work with future obj
    QString name = "name";

    QFuture<void> f = QtConcurrent::run(with_future_result, name, 5);
    qInfo() << "Some work here";

    f.waitForFinished();

    qInfo() << "Done!";

    return a.exec();
}
