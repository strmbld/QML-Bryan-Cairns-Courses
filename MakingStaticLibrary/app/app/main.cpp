
#include <QCoreApplication>

#include "inc/lib.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Lib lib;
    lib.test();

    return a.exec();
}
