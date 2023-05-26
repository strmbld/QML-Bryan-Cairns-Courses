
#include <QCoreApplication>

#include "../lib/lib_global.h"
#include "../lib/lib.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Lib lib;
    lib.test();

    return a.exec();
}
