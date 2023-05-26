#ifndef MANAGER_H
#define MANAGER_H


#include <QObject>
#include <QDebug>
#include <QFuture>
#include <QtConcurrent>

#include "worker.h"


class Manager : public QObject
{
private:
    Q_OBJECT

    static void create_worker(Manager* manager);
public:
    explicit Manager(QObject *parent = nullptr);
    ~Manager();

public slots:
    void process();
    void quit();

signals:
    void start();
    void stop();

};

#endif // MANAGER_H
