#include "worker.h"


Worker::Worker(QObject *parent)
    : QObject{parent}
{
    // qInfo() << m_manager.supportedSchemes();
    connect(&m_manager, &QNetworkAccessManager::authenticationRequired, this, &Worker::authenticationRequired);
    connect(&m_manager, &QNetworkAccessManager::encrypted, this, &Worker::encrypted);
    connect(&m_manager, &QNetworkAccessManager::preSharedKeyAuthenticationRequired, this, &Worker::preSharedKeyAuthenticationRequired);
    connect(&m_manager, &QNetworkAccessManager::proxyAuthenticationRequired, this, &Worker::proxyAuthenticationRequied);
    connect(&m_manager, &QNetworkAccessManager::sslErrors, this, &Worker::sslErrors);
}


void Worker::readyRead()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if(reply) {
        qInfo() << reply->readAll();
    }
}

void Worker::authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    Q_UNUSED(authenticator);
    qInfo() << "authenticationRequired";
}

void Worker::encrypted(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    qInfo() << "encrypted";
}

void Worker::finished(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    qInfo() << "finished";
    reply->deleteLater();
}

void Worker::preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    Q_UNUSED(authenticator);
    qInfo() << "preSharedKeyAuthenticationRequired";
}

void Worker::proxyAuthenticationRequied(const QNetworkProxy &proxy, QAuthenticator *authenticator)
{
    Q_UNUSED(proxy);
    Q_UNUSED(authenticator);
    qInfo() << "proxyAuthenticationRequied";
}

void Worker::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    Q_UNUSED(reply);
    Q_UNUSED(errors);
    qInfo() << "sslErrors";
}


void Worker::get(QString url)
{
    QNetworkRequest request = QNetworkRequest(QUrl(url));
    QNetworkReply* reply = m_manager.get(request);
    connect(reply, &QNetworkReply::readyRead, this, &Worker::readyRead);
}

void Worker::post(QString url, QByteArray data)
{
    QNetworkRequest request = QNetworkRequest(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/plain"); // mime type
    QNetworkReply* reply = m_manager.post(request, data);
    connect(reply, &QNetworkReply::readyRead, this, &Worker::readyRead);
}
