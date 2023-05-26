#include "backend.h"

Backend::Backend(QObject *parent)
    : QObject{parent}
{
    m_path = QDir::currentPath();
    m_path.append(QDir::separator());
    m_path.append("file.txt");
}

void Backend::setPath(QString path)
{
    QString rem = "file:///";
    path.remove(rem);
    m_path = path;

    emit pathChanged();
}

QString Backend::data()
{
    QFile file(m_path);

    if(!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Unable to read file!" + file.errorString();

        return "";
    }

    QTextStream in(&file);
    QString data = in.readAll();

    file.close();

    return data;
}

void Backend::setData(QString value)
{
    QFile file(m_path);

    if(!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Unable to write into file!" + file.errorString();

        return;
    }

    QTextStream out(&file);
    out << value;

    file.close();

    emit dataChanged();
}
