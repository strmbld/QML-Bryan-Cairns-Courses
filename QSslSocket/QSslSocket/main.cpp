#include <QCoreApplication>

#include "client.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    // client.connectToHost("www.google.com", 80);
    client.connectToHost("google.com", 443);

    return a.exec();
}
