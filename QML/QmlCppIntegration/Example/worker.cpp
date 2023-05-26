#include "worker.h"


Worker::Worker(QObject *parent)
    : QObject{parent}
{
    m_timer.setInterval(1000);
    connect(&m_timer, &QTimer::timeout, this, &Worker::timeout);
}


void Worker::timeout()
{
    m_value++;

    emit progress();

    if(m_value > 99) {
        stop();
    }
}

void Worker::start()
{
    m_value = 0;
    m_timer.start();

    emit started();
}

void Worker::stop()
{
    m_timer.stop();

    emit stopped();
}

void Worker::pause()
{
    m_timer.stop();

    emit paused();
}

void Worker::resume()
{
    m_timer.start();

    emit resumed();
}
