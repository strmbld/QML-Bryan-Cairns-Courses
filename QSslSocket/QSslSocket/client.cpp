#include "client.h"


Client::Client(QObject *parent)
    : QObject{parent}
{
    connect(&m_socket, &QSslSocket::connected, this, &Client::connected);
    connect(&m_socket, &QSslSocket::disconnected, this, &Client::disconnected);
    connect(&m_socket, &QSslSocket::stateChanged, this, &Client::stateChanged);
    connect(&m_socket, &QSslSocket::readyRead, this, &Client::readyRead);
    connect(&m_socket, &QSslSocket::errorOccurred, this, &Client::error);

    connect(&m_socket, &QSslSocket::encrypted, this, &Client::encrypted);
    connect(&m_socket, &QSslSocket::encryptedBytesWritten, this, &Client::encryptedBytesWritten);
    connect(&m_socket, &QSslSocket::modeChanged, this, &Client::modeChanged);
    connect(&m_socket, &QSslSocket::peerVerifyError, this, &Client::peerVerifyError);
    connect(&m_socket, &QSslSocket::preSharedKeyAuthenticationRequired, this, &Client::preSharedKeyAuthenticationRequired);
    connect(&m_socket, QOverload<const QList<QSslError>&>::of(&QSslSocket::sslErrors), this, &Client::sslErrors);
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

void Client::encrypted()
{
    qInfo() << "Encrypted";
}

void Client::encryptedBytesWritten(qint64 written)
{
    qInfo() << "encryptedBytesWritten: " << written;
}

void Client::modeChanged(QSslSocket::SslMode mode)
{
    qInfo() << "SslMode: " << mode;
}

void Client::peerVerifyError(const QSslError &error)
{
    qInfo() << "peerVerifyError: " << error.errorString();
}

void Client::preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenticator)
{
    qInfo() << "Preshared key required!";
}

void Client::sslErrors(const QList<QSslError> &errors)
{
    qInfo() << "###### SSL Errors ######";
    for (int i = 0; i < errors.count(); ++i) {
        qInfo() << errors[i].errorString();
    }
}

void Client::connectToHost(QString host, quint16 port)
{
    if(m_socket.isOpen()) disconnect();

    qInfo() << "Connecting to: " << host << " on port " << port;

    // m_socket.connectToHost(host, port);
    m_socket.setProtocol(QSsl::SecureProtocols);
    m_socket.connectToHostEncrypted(host, port);
}

void Client::disconnect()
{
    m_socket.close();
    m_socket.waitForDisconnected();
}
