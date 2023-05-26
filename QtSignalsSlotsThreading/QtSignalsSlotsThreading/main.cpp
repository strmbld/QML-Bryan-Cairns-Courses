#include <QCoreApplication>
#include <QThread>

#include "producer.h"
#include "consumer.h"


void cleanup()
{
    qInfo() << "Cleanup";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread::currentThread()->setObjectName("Main Thread");

    QThread producer_thread;
    producer_thread.setObjectName("Producer Thread");

    Producer* producer = new Producer();
    producer->moveToThread(&producer_thread);
    QObject::connect(&producer_thread, &QThread::started, producer, &Producer::start);

    QThread consumer_thread;
    consumer_thread.setObjectName("Consumer Thread");

    Consumer* consumer = new Consumer();
    consumer->moveToThread(&consumer_thread);

    // should be Qt::QueuedConnection instead of Direct
    QObject::connect(producer, &Producer::produce, consumer, &Consumer::consume);
    QObject::connect(producer, &Producer::finished, &producer_thread, &QThread::quit);
    QObject::connect(&producer_thread, &QThread::finished, &consumer_thread, &QThread::quit);
    QObject::connect(&consumer_thread, &QThread::finished, consumer, &Consumer::deleteLater);
    QObject::connect(&producer_thread, &QThread::finished, producer, &Producer::deleteLater);
    QObject::connect(&consumer_thread, &QThread::finished, &a, &QCoreApplication::quit);
    QObject::connect(&a, &QCoreApplication::aboutToQuit, &cleanup);

    // consumer/subscriber/listener MUST RUN FIRST!!! to prevent loosing messages
    consumer_thread.start();
    producer_thread.start();

    return a.exec();
}
