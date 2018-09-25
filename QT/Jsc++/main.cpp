#include "JSCallC.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JSCallC w;
    w.show();
    return a.exec();
}
