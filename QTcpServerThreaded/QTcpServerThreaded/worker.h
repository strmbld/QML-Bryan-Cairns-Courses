
#ifndef WORKER_H
#define WORKER_H


#include <QObject>
#include <QDebug>
#include <QRunnable>
#include <QThread>
#include <QTcpSocket>


class Worker : public QObject, public QRunnable
{
private:
    Q_OBJECT

    qintptr m_handle;
public:
    explicit Worker(QObject *parent = nullptr , qintptr handle = 0);

    void run() override;
};

#endif // WORKER_H
