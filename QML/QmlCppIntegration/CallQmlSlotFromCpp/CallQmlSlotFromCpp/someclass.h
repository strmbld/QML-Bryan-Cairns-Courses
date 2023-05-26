#ifndef SOMECLASS_H
#define SOMECLASS_H

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QVariant>
#include <QDebug>


class SomeClass : public QObject
{
private:
    Q_OBJECT

    QTimer m_timer;
    QString m_display;

private slots:
    void timeout();

public:
    explicit SomeClass(QObject *parent = nullptr);

public slots:
    void start();
    void stop();

signals:
    void notice(QVariant data);

};

#endif // SOMECLASS_H
