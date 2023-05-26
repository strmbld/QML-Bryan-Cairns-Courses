#include "worker.h"


Worker::Worker(QObject *parent, qintptr handle)
    : QObject{parent}
    , m_handle(handle)
{

}


void Worker::run()
{
    qInfo() << this << " run " << QThread::currentThread();

    QTcpSocket* socket = new QTcpSocket(nullptr);
    if(!socket->setSocketDescriptor(m_handle)) {
        qCritical() << socket->errorString();
        delete socket;

        return;
    }

    socket->waitForReadyRead();
    QByteArray request = socket->readAll();
    qInfo() << "Request length: " << request.length();

    QByteArray data("Hello World!");
    QByteArray response;
    response.append("HTTP/1.1 200 OK\r\n");
    response.append("Content-Type: text/plain\r\n");
    response.append("Content-Length: " + QString::number(data.length()).toUtf8() + "\r\n");
    response.append("Connection: close\r\n");
    response.append("\r\n");
    response.append(data);

    socket->write(response);
    socket->waitForBytesWritten();
    socket->close();
    socket->deleteLater();

    qInfo() << this << " done " << QThread::currentThread();
}
