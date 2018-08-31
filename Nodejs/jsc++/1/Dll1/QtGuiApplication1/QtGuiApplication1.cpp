#include "QtGuiApplication1.h"
#include "Dll1.h"
QtGuiApplication1::QtGuiApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    int ii = add(2, 3);
    ui.setupUi(this);
}
