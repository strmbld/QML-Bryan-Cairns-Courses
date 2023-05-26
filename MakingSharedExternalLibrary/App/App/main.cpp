
#include <QCoreApplication>

#include "inc/ExternalSharedLib_global.h"
#include "inc/externalsharedlib.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ExternalSharedLib lib;
    lib.test();

    return a.exec();
}
