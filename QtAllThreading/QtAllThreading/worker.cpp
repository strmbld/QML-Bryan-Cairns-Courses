#include "worker.h"


Worker::Worker(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "Constructed on " << QThread::currentThread();
    connect(&m_timer, &QTimer::timeout, this, &Worker::timeout);
    m_timer.setInterval(1000);
}

Worker::~Worker()
{
    qInfo() << this << "Deconstructed on " << QThread::currentThread();
}


void Worker::start()
{
    qInfo() << this << "Started on " << QThread::currentThread();

    m_timer.start();
    m_loop.exec();

    qInfo() << this << "Loop finished on " << QThread::currentThread();

    // this->deleteLater();
    delete this;
}

void Worker::stop()
{
    qInfo() << this << "Stopping on " << QThread::currentThread();

    m_timer.stop();
    m_loop.quit();

    qInfo() << this << "Stopped on " << QThread::currentThread();
}

void Worker::timeout()
{
    qInfo() << this << "Timed out on " << QThread::currentThread();
}
