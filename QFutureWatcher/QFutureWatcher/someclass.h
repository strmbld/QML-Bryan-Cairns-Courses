#ifndef SOMECLASS_H
#define SOMECLASS_H


#include <QObject>
#include <QDebug>


class SomeClass : public QObject
{
private:
    Q_OBJECT

public:
    explicit SomeClass(QObject *parent = nullptr);

public slots:
    void finished();

signals:

};

#endif // SOMECLASS_H
