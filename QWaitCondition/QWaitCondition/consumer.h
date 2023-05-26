#ifndef CONSUMER_H
#define CONSUMER_H


#include <QObject>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>


class Consumer : public QObject
{
private:
    Q_OBJECT

    QMutex* m_mutex;
    QWaitCondition* m_value_ready;
    int* m_value;
public:
    explicit Consumer(QMutex* mutex, QWaitCondition* value_ready, int* value, QObject *parent = nullptr);
public slots:
    void run();
signals:

};

#endif // CONSUMER_H
