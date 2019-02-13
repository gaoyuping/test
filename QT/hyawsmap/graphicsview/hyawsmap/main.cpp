#include "hyawsmap.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hyawsmap w;
    w.show();
    return a.exec();
}
