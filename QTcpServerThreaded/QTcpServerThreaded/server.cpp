
#include "server.h"

Server::Server(QObject *parent)
    : QTcpServer{parent}
{
    m_pool.setMaxThreadCount(200);
    qInfo() << "MaxThreadCount: " << m_pool.maxThreadCount();
}

void Server::start(quint16 port)
{
    qInfo() << this << " start " << QThread::currentThread();

    if(!listen(QHostAddress::Any, port)) {
        qCritical() << errorString();

        return;
    }

    qInfo() << "Server started on " << port;
}

void Server::quit()
{
    close();
    qInfo() << "Server stopped";
}

void Server::incomingConnection(qintptr handle)
{
    qInfo() << "Incoming connection " << handle << " on " << QThread::currentThread();
    Worker* worker = new Worker(nullptr, handle);
    worker->setAutoDelete(true);
    m_pool.start(worker);
}
