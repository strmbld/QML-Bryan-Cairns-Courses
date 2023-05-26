#include "client.h"


Client::Client(QObject *parent)
    : QObject{parent}
{
    connect(&m_socket, &QTcpSocket::connected, this, &Client::connected);
    connect(&m_socket, &QTcpSocket::disconnected, this, &Client::disconnected);
    connect(&m_socket, &QTcpSocket::stateChanged, this, &Client::stateChanged);
    connect(&m_socket, &QTcpSocket::readyRead, this, &Client::readyRead);
    connect(&m_socket, &QTcpSocket::errorOccurred, this, &Client::error);
    // proxy
    QNetworkProxy proxy(QNetworkProxy::HttpProxy, "??????", 0);
    // auth
    // proxy.setUser("user");
    // proxy.setPassword("pass");
    QNetworkProxy::setApplicationProxy(proxy); // m_socket.setProxy(proxy);
}


void Client::connected()
{
    qInfo() << "Connected" << '\n'
            << "Sending";

    m_socket.write("hello there");
}

void Client::disconnected()
{
    qInfo() << "Disconnected";
}

void Client::error(QAbstractSocket::SocketError socketError)
{
    qInfo() << "Error: " << socketError << " " << m_socket.errorString();
}

void Client::stateChanged(QAbstractSocket::SocketState socketState)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    qInfo() << "State: " << metaEnum.valueToKey(socketState);
}

void Client::readyRead()
{
    qInfo() << "Data from: " << sender() << " bytes: " << m_socket.bytesAvailable();
    qInfo() << "Data: " << m_socket.readAll();
}

void Client::connectToHost(QString host, quint16 port)
{
    if(m_socket.isOpen()) disconnect();

    qInfo() << "Connecting to: " << host << " on port " << port;

    m_socket.connectToHost(host, port);
}

void Client::disconnect()
{
    m_socket.close();
    m_socket.waitForDisconnected();
}
