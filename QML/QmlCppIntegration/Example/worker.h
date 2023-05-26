#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QTimer>


class Worker : public QObject
{
private:
    Q_OBJECT

    Q_PROPERTY(int workload READ value WRITE setValue NOTIFY progress)


    QTimer m_timer;
    int m_value;

private slots:
    void timeout();

public:
    explicit Worker(QObject *parent = nullptr);

    inline int value() { return m_value; }
    inline void setValue(int value) { m_value = value; emit progress(); } // value should be QVariant type if comes from QML but prolly will work as is

public slots:
    void start();
    void stop();
    void pause();
    void resume();

signals:
    void started();
    void stopped();
    void paused();
    void resumed();

    void progress();
};

#endif // WORKER_H
