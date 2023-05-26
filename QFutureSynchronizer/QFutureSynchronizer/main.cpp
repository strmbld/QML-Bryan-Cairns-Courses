#include <QCoreApplication>
#include <QtConcurrent>


void do_work(int value)
{
    for (int i = 0; i < 10; ++i) {
        QThread::currentThread()->msleep(100);
        qInfo() << "Thread: " << value << " = " << i;
    }
}

void run()
{
    QFutureSynchronizer<void> sync;
    for (int i = 0; i < 3; ++i) {
        QFuture<void> f = QtConcurrent::run(&do_work, i);
        sync.addFuture(f);
    }

    sync.waitForFinished(); // can omit since waitForFinished() called in QFutureSynchronizer destructor
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    run();

    qInfo() << "Done!";

    return a.exec();
}
