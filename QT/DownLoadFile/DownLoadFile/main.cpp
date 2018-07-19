#include "downloadfile.h"
#include <QtWidgets/QApplication>
#include "QALLWidget.h"

class globalApp : public QApplication
{
public:
    globalApp(int &argc, char **argv) :QApplication(argc, argv)
    {

    };
    //    ~globalApp();
    bool notify(QObject* object, QEvent *ev)
    {
        if (0 == object->objectName().compare("DownLoadFileClassWindow") && ev->type() == QEvent::MouseButtonPress)
        {
            emit QALLWidgetNotify::GetInstance()->signalhide(object, ev);
        }
        return QApplication::notify(object, ev);
    };
};

int main(int argc, char *argv[])
{
    int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    tmpFlag |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(tmpFlag);

    globalApp a(argc, argv);
    DownLoadFile w;
    w.show();
    return a.exec();
}
