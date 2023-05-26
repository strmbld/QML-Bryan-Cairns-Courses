#include "dirhelper.h"

DirHelper::DirHelper(QObject *parent)
    : QObject{parent}
{

}

QStringList DirHelper::files() const
{
    QFileInfoList list = m_dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Files);
    QStringList fileList;

    for (int i = 0; i < list.count(); ++i) {
        fileList.append(list[i].filePath());
    }

    return fileList;
}
