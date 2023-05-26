#ifndef WORKER_H
#define WORKER_H


#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QDateTime>
#include <QNetworkDatagram>


class Worker : public QObject
{
private:
    Q_OBJECT

    QUdpSocket m_socket;
    QTimer m_timer;
    quint16 m_port = 2023; // <1024 are service ports requiring admin privileges
public:
    explicit Worker(QObject *parent = nullptr);

public slots:
    void start();
    void stop();
    void timeout();
    void readyRead();
    void broadcast();

signals:

};

#endif // WORKER_H
