#include "mvd_list.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MVD_list w;
    w.show();
    return a.exec();
}
