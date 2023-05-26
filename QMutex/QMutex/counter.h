#ifndef COUNTER_H
#define COUNTER_H


#include <QObject>
#include <QDebug>
#include <QRunnable>
#include <QThread>
#include <QRandomGenerator>
#include <QMutex>


class Counter : public QRunnable
{
private:
    int* m_value;
    QMutex* m_mutex;

public:
    Counter(QMutex* mutex, int* value);
    ~Counter();


    void run() override;
};

#endif // COUNTER_H
