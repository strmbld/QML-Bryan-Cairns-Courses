#include "producer.h"


Producer::Producer(QMutex *mutex, QWaitCondition *value_ready, int *value, QObject *parent)
{
    // Q_UNUSED(parent);
    m_mutex = mutex;
    m_value_ready = value_ready;
    m_value = value;
}


void Producer::run()
{
    qInfo() << "Producer is running";

    QThread::currentThread()->msleep(3000);

    m_mutex->lock();
    qInfo() << "Producer is creating the value";
    *m_value = QRandomGenerator::global()->bounded(1000);
    qInfo() << "Producer is waking up the consumer";
    m_mutex->unlock();

    m_value_ready->wakeAll();
}
