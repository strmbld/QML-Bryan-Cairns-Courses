#ifndef DIRHELPER_H
#define DIRHELPER_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>


class DirHelper : public QObject
{
private:
    Q_OBJECT

    Q_PROPERTY(QString path READ path WRITE setPath CONSTANT)
    Q_PROPERTY(QStringList files READ files CONSTANT)

    QDir m_dir;

public:
    explicit DirHelper(QObject *parent = nullptr);


    inline QString path() const { return m_dir.path(); }
    inline void setPath(QString value) { m_dir.setPath(value); }
    QStringList files() const;

signals:

};

#endif // DIRHELPER_H
