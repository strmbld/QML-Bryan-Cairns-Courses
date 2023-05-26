#ifndef PRODUCER_H
#define PRODUCER_H


#include <QObject>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>
#include <QThread>
#include <QRandomGenerator>


class Producer : public QObject
{
private:
    Q_OBJECT

    QMutex* m_mutex;
    QWaitCondition* m_value_ready;
    int* m_value;
public:
    explicit Producer(QMutex* mutex, QWaitCondition* value_ready, int* value, QObject *parent = nullptr);


public slots:
    void run();
signals:

};

#endif // PRODUCER_H
