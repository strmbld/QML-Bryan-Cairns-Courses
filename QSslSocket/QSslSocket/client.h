#ifndef CLIENT_H
#define CLIENT_H


#include <QObject>
#include <QAbstractSocket>
#include <QMetaEnum>
#include <QSslSocket>
#include <QSslPreSharedKeyAuthenticator>


class Client : public QObject
{
private:
    Q_OBJECT

    QSslSocket m_socket;

private slots:
    void connected();
    void disconnected();
    void error(QAbstractSocket::SocketError socketError);
    void stateChanged(QAbstractSocket::SocketState socketState);
    void readyRead();
    // SSL
    void encrypted();
    void encryptedBytesWritten(qint64 written);
    void modeChanged(QSslSocket::SslMode mode);
    void peerVerifyError(const QSslError& error);
    void preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator* authenticator);
    void sslErrors(const QList<QSslError>& errors);

public:
    explicit Client(QObject *parent = nullptr);

public slots:
    void connectToHost(QString host, quint16 port);
    void disconnect();

signals:

};

#endif // CLIENT_H
