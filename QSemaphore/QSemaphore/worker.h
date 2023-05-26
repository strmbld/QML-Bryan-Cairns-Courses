#ifndef WORKER_H
#define WORKER_H


#include <QObject>
#include <QSemaphore>
#include <QDebug>
#include <QThread>
#include <QRandomGenerator>


class Worker : public QObject
{
private:
    Q_OBJECT

    QSemaphore* m_sema;
    QList<int>* m_values;
public:
    explicit Worker(QSemaphore* sema, QList<int>* values, QObject *parent = nullptr);

public slots:
    void run();
};

#endif // WORKER_H
