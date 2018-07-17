#include "makeavatar.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MakeAvatar w;
    w.show();
    return a.exec();
}
