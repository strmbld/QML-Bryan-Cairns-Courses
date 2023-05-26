
#ifndef SERVER_H
#define SERVER_H


#include <QObject>
#include <QThreadPool>
#include <QTcpServer>

#include "worker.h"


class Server : public QTcpServer
{
private:
    Q_OBJECT

    QThreadPool m_pool;
public:
    explicit Server(QObject *parent = nullptr);

public slots:
    void start(quint16 port);
    void quit();

signals:


    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle) override;
};

#endif // SERVER_H
