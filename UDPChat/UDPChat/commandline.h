#ifndef COMMANDLINE_H
#define COMMANDLINE_H


#include <QObject>
#include <QTextStream>


class CommandLine : public QObject
{
private:
    Q_OBJECT

    QTextStream cin;
public:
    explicit CommandLine(QObject *parent = nullptr, FILE* fileHandler = nullptr);

    [[noreturn]] void monitor();

signals:
    void command(QString value);
};

#endif // COMMANDLINE_H
