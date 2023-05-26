#include "commandline.h"


CommandLine::CommandLine(QObject *parent, FILE *fileHandler)
    : QObject{parent}, cin(fileHandler)
{

}

void CommandLine::monitor()
{
    while (1) {
        QString value = cin.readLine();

        emit command(value);
    }
}
