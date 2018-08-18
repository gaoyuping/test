#include "sqlite.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SqLite w;
    w.show();
    return a.exec();
}
