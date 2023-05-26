#include "chat.h"


Chat::Chat(QObject *parent)
    : QObject{parent}
{
    if(!m_socket.bind(m_port, QUdpSocket::ShareAddress)) {
        qInfo() << m_socket.errorString();

        return;
    }

    qInfo() << "Started on: " << m_socket.localAddress() << ":" << m_socket.localPort();
    connect(&m_socket, &QUdpSocket::readyRead, this, &Chat::readyRead);
}


void Chat::command(QString value)
{
    QString message = m_name + ": ";
    if(m_name.isEmpty()) {
        m_name = value;
        message = m_name + ": joined";
        send(message);

        return;
    }

    message.append(value);
    send(message);
}

void Chat::send(QString value)
{
    QByteArray data = value.toUtf8();
    QNetworkDatagram datagram(data, QHostAddress::Broadcast, m_port);

    if(!m_socket.writeDatagram(datagram)) {
        qInfo() << m_socket.errorString();
    }
}

void Chat::readyRead()
{
    while (m_socket.hasPendingDatagrams()) {
        QNetworkDatagram datagram = m_socket.receiveDatagram();
        qInfo() << datagram.data();
    }
}
