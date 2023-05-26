#include "worker.h"


Worker::Worker(QObject *parent)
    : QObject{parent}
{
    connect(&m_timer, &QTimer::timeout, this, &Worker::timeout);
    connect(&m_socket, &QUdpSocket::readyRead, this, &Worker::readyRead);
    m_timer.setInterval(1000);
}


void Worker::start()
{
    // change bind mode to QAbstractSocket::ShareAddress if have issues
    if(!m_socket.bind(m_port)) {
        qInfo() << m_socket.errorString();

        return;
    }

    qInfo() << "Started UDP connection on " << m_socket.localAddress() << ":" << m_socket.localPort();

    broadcast();
}

void Worker::stop()
{
    m_timer.stop();
    m_socket.close();

    qInfo() << "Stopped";
}

void Worker::timeout()
{
    QString current_date = QDateTime::currentDateTime().toString();
    QByteArray data = current_date.toUtf8();
    QNetworkDatagram datagram(data, QHostAddress::Broadcast, m_port);
    qInfo() << "Send: " << data;
    m_socket.writeDatagram(datagram);
}

void Worker::readyRead()
{
    while (m_socket.hasPendingDatagrams()) {
        QNetworkDatagram datagram = m_socket.receiveDatagram();
        qInfo() << "Read: " << datagram.data() << " from " << datagram.senderAddress() << ":" << datagram.senderPort();
    }
}

void Worker::broadcast()
{
    qInfo() << "Broadcasting...";
    m_timer.start();
}
