#include "widget.h"


Widget::Widget(QObject *parent)
    : QObject{parent}
{
    m_is_sender = false;
}


void Widget::run()
{
    if(m_is_sender) {
        qInfo() << this << "Starting work...";

        emit started();

        for (int i = 0; i < 10; ++i) {
            qInfo() << this << "Update...";

            emit update(i);
            QThread::currentThread()->msleep(500);
        }

        qInfo() << this << "Finished!";

        emit finished();

        qInfo() << this << "Done!";

        return;
    }

    qInfo() << this << "Waiting for signals...";

    m_is_active = true;

    while (m_is_active) {
        QThread::currentThread()->msleep(100);
    }

    qInfo() << this << "Done!";
}

void Widget::work_started()
{
    qInfo() << this << "Started" << sender();
}

void Widget::work_finished()
{
    qInfo() << this << "Finished" << sender();

    m_is_active = false;
}

void Widget::work_ready(int i)
{
    qInfo() << this << "Work" << i << sender();
}
