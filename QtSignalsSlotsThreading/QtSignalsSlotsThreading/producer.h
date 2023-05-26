#ifndef PRODUCER_H
#define PRODUCER_H


#include <QObject>
#include <QRandomGenerator>
#include <QDebug>
#include <QThread>
#include <QTimer>


class Producer : public QObject
{
private:
    Q_OBJECT

    QTimer* m_timer;
    int m_count;
    int m_max;
public:
    explicit Producer(QObject *parent = nullptr);
    ~Producer();

signals:
    void produce(int value);
    void finished();

public slots:
    void start();

private slots:
    void timeout();
};

#endif // PRODUCER_H
