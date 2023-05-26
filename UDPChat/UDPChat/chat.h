#ifndef CHAT_H
#define CHAT_H


#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>


class Chat : public QObject
{
private:
    Q_OBJECT

    QString m_name;
    QUdpSocket m_socket;
    quint16 m_port = 2023;

public:
    explicit Chat(QObject *parent = nullptr);

public slots:
    void command(QString value);
    void send(QString value);
    void readyRead();
signals:

};

#endif // CHAT_H
