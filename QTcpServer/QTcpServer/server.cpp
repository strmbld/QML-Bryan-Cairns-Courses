
#include "server.h"

Server::Server(QObject *parent)
    : QObject{parent}
{
    connect(&m_server, &QTcpServer::newConnection, this, &Server::newConnection);
}

void Server::start()
{
    if(!m_server.listen(QHostAddress::Any, 2023)) {
        qWarning() << m_server.errorString();

        return;
    }

    qInfo() << "Listening...";
}

void Server::quit()
{
    m_server.close();
}

void Server::newConnection()
{
    QTcpSocket* socket = m_server.nextPendingConnection();
    connect(socket, &QTcpSocket::disconnected, this, &Server::disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &Server::readyRead);
    qInfo() << "Connected " << socket;
}

void Server::disconnected()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    qInfo() << "Disconnected " << socket;
    qInfo() << "Parent " << socket->parent();
    socket->deleteLater();
}

void Server::readyRead()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    qInfo() << "readyRead " << socket;
    qInfo() << socket->readAll();
}
