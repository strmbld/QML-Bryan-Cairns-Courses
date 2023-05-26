#include <QCoreApplication>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>

#include "producer.h"
#include "consumer.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QWaitCondition value_ready;
    QMutex mutex;
    QThread p_thread;
    p_thread.setObjectName("Producer thread");
    QThread c_thread;
    c_thread.setObjectName("Consumer thread");
    int value = 0;

    Producer* producer = new Producer(&mutex, &value_ready, &value);
    Consumer* consumer = new Consumer(&mutex, &value_ready, &value);

    producer->moveToThread(&p_thread);
    consumer->moveToThread(&c_thread);

    QObject::connect(&p_thread, &QThread::started, producer, &Producer::run);
    QObject::connect(&c_thread, &QThread::started, consumer, &Consumer::run);

    // usually consumer should start run "listening" first to prevent missing produced data
    // in current case producer/consumer starting order does no matter
    p_thread.start();
    c_thread.start();

    return a.exec();
}
