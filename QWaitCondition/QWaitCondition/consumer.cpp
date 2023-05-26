#include "consumer.h"


Consumer::Consumer(QMutex *mutex, QWaitCondition *value_ready, int *value, QObject *parent)
{
    // Q_UNUSED(parent);
    m_mutex = mutex;
    m_value_ready = value_ready;
    m_value = value;
}

void Consumer::run()
{
    qInfo() << "The Consumer is running";
    m_mutex->lock();
    qInfo() << "The Consumer locked thread with mutex";

    if(*m_value == 0) {
        qInfo() << "The Consumer is waiting for a value";

        m_value_ready->wait(m_mutex); // wait() unlocks m_mutex here
    }

    qInfo() << "Consuming: " << *m_value;
}
