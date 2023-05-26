#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QThreadPool>

#include "counter.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    QThreadPool* pool = QThreadPool::globalInstance();
    qInfo() << pool->maxThreadCount() << " Threads";

    QMutex mutex;
    int value = 0;

    for (int i = 0; i < 100; ++i) {
        Counter* c = new Counter(&mutex, &value);
        c->setAutoDelete(true);
        pool->start(c);
    }

    qDebug() << pool->parent();
    pool->deleteLater();

    return a.exec();
}
