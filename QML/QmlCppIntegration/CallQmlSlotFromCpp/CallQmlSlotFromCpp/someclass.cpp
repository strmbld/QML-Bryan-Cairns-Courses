#include "someclass.h"


SomeClass::SomeClass(QObject *parent)
    : QObject{parent}
{
    connect(&m_timer, &QTimer::timeout, this, &SomeClass::timeout);
    m_timer.setInterval(1000);
    m_display = "Starting";
    qInfo() << m_display;

    emit notice(QVariant(m_display));
}


void SomeClass::timeout()
{
    m_display = QDateTime::currentDateTime().toString();
    qInfo() << m_display;

    emit notice(QVariant(m_display));
}

void SomeClass::start()
{
    m_display = "Starting...";
    qInfo() << m_display;

    emit notice(QVariant(m_display));

    m_timer.start();
}

void SomeClass::stop()
{
    m_timer.stop();
    m_display = "Stopped";
    qInfo() << m_display;

    emit notice(QVariant(m_display));
}
