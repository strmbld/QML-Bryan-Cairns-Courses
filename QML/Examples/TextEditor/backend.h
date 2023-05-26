#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QDebug>
#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QTextStream>


class Backend : public QObject
{
private:
    Q_OBJECT

    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString data READ data WRITE setData NOTIFY dataChanged)


    QString m_path;

public:
    explicit Backend(QObject *parent = nullptr);


    inline QString path() const { return m_path; }
    void setPath(QString path);
    QString data();
    void setData(QString value);

signals:
    void pathChanged();
    void dataChanged();
};

#endif // BACKEND_H
