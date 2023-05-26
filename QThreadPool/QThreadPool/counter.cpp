#include "counter.h"


Counter::Counter()
{

}

Counter::~Counter()
{
    qDebug() << "Deconstructed: " << this << " at " << QThread::currentThread();
}


void Counter::run()
{
    qInfo() << "Starting: " << QThread::currentThread();

    for (int i = 0; i < 20; ++i) {
        qInfo() << QThread::currentThread() << " = " << i;
        auto value = static_cast<unsigned long>(QRandomGenerator::global()->bounded(100));
        QThread::currentThread()->msleep(value);
    }

    qInfo() << "Finished: " << QThread::currentThread();
}
