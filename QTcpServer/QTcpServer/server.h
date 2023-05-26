
#ifndef SERVER_H
#define SERVER_H


#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>


class Server : public QObject
{
private:
    Q_OBJECT

    QTcpServer m_server;
public:
    explicit Server(QObject *parent = nullptr);

public slots:
    void start();
    void quit();
    void newConnection();
    void disconnected();
    void readyRead();
signals:

};

#endif // SERVER_H
