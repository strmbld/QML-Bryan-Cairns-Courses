
#include <QCoreApplication>

#include "server.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    server.start(2023);

    return a.exec();
}
