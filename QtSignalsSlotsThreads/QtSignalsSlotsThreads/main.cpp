#include <QCoreApplication>
#include <QThreadPool>

#include "widget.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Widget* consumer = new Widget();
    Widget* producer = new Widget();

    consumer->setObjectName("Consumer");
    producer->setObjectName("Producer");
    consumer->setAutoDelete(true);
    producer->setAutoDelete(true);

    producer->set_is_sender(true);

    QObject::connect(producer, &Widget::started, consumer, &Widget::work_started, Qt::QueuedConnection);
    QObject::connect(producer, &Widget::update, consumer, &Widget::work_ready, Qt::QueuedConnection);
    QObject::connect(producer, &Widget::finished, consumer, &Widget::work_finished, Qt::QueuedConnection);

    QThreadPool::globalInstance()->start(consumer);
    QThreadPool::globalInstance()->start(producer);

    return a.exec();
}
