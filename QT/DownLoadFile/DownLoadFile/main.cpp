﻿#include "downloadfile.h"
#include <QtWidgets/QApplication>
#include "QALLWidget.h"
#include "vld.h"//需要安装VLD
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

    QApplication a(argc, argv);
//     QNetworkAccessManager networkaccessmanager;
//     GNetworkAccessManager::GetInstance()->setNetworkAccessManager(networkaccessmanager);
    DownLoadFile w;
    w.show();
    return a.exec();
}
