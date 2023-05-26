
#ifndef WORKER_H
#define WORKER_H


#include <QObject>
#include <QNetworkReply>
#include <QAuthenticator>


class Worker : public QObject
{
private:
    Q_OBJECT

    QNetworkAccessManager m_manager;

private slots:
    void readyRead();
    void authenticationRequired(QNetworkReply* reply, QAuthenticator* authenticator);
    void encrypted(QNetworkReply* reply);
    void finished(QNetworkReply* reply);
    void preSharedKeyAuthenticationRequired(QNetworkReply* reply, QSslPreSharedKeyAuthenticator* authenticator);
    void proxyAuthenticationRequied(const QNetworkProxy& proxy, QAuthenticator* authenticator);
    void sslErrors(QNetworkReply* reply, const QList<QSslError>& errors);
public:
    explicit Worker(QObject *parent = nullptr);

public slots:
    void get(QString url);
    void post(QString url, QByteArray data);

signals:

};

#endif // WORKER_H
