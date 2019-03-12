#include "treedrag.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    treedrag w;
    w.show();
    return a.exec();
}
