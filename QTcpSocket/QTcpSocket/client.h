#ifndef CLIENT_H
#define CLIENT_H


#include <QObject>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QMetaEnum>


class Client : public QObject
{
private:
    Q_OBJECT

    QTcpSocket m_socket;

private slots:
    void connected();
    void disconnected();
    void error(QAbstractSocket::SocketError socketError);
    void stateChanged(QAbstractSocket::SocketState socketState);
    void readyRead();

public:
    explicit Client(QObject *parent = nullptr);

public slots:
    void connectToHost(QString host, quint16 port);
    void disconnect();

signals:

};

#endif // CLIENT_H
