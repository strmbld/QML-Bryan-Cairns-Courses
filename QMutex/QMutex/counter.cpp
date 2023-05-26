#include "counter.h"


Counter::Counter(QMutex *mutex, int *value)
{
    m_value = value;
    m_mutex = mutex;
}

Counter::~Counter()
{
    qDebug() << "Deconstructed: " << this << " at " << QThread::currentThread();
}


void Counter::run()
{
    m_mutex->lock();

    qInfo() << "Starting: " << QThread::currentThread();

    QThread::currentThread()->msleep(50);

    *m_value += 1;
    qInfo() << *m_value << QThread::currentThread();

    qInfo() << "Finished: " << QThread::currentThread();

    m_mutex->unlock();
}
