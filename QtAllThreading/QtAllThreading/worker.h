#ifndef WORKER_H
#define WORKER_H


#include <QObject>
#include <QTimer>
#include <QEventLoop>
#include <QDebug>
#include <QThread>


class Worker : public QObject
{
private:
    Q_OBJECT

    QTimer m_timer;
    QEventLoop m_loop;
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();

public slots:
    void start();
    void stop();
    void timeout();

signals:

};

#endif // WORKER_H
