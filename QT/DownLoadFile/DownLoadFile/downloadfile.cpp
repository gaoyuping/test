#include "downloadfile.h"

#include <QMovie>
DownLoadFile::DownLoadFile(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    tmp = new QALLWidget(this);
    tmp->move(0, 0);
    tmp->resize(100, 100);
    tmp->show();
    tmp->raise();

//     QMovie *m_loadMovie = new QMovie(R"(E:\code\toon_PC_Client\toonqt\Toon\Resources\fenghuang\ladingGif.gif)");
//     m_loadMovie->setScaledSize(QSize(60, 60));
//     ui.label->setMovie(m_loadMovie);
//     m_loadMovie->start();
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\2.rar)");
//      Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\1.rar)", [&](bool bsuccess, QString strmsg, QJsonObject JsonData){
//         qInfo() << "sssssssssssssssssssssssss" << bsuccess;
//         if (bsuccess)
//         {
//             qInfo() << "JsonData = " << JsonData;
//         }
//         else
//         {
//             qInfo() << "strmsg = " << strmsg;
//         }
//     });
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\2.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\3.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\4.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\5.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\6.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\7.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\8.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\9.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\10.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\11.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\12.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\13.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\14.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\15.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\16.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\17.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\18.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\19.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\20.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\21.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\22.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\23.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\24.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\25.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\26.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\27.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\28.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\29.rar)");
//     Downfile::GetInstance()->getDownLoadFile(R"(http://file0203.daimg.com/2018/1807/DAimG_2018072235970747T4R2.rar)", R"(F:\D\30.rar)");
}

DownLoadFile::~DownLoadFile()
{

}

#include <QMouseEvent>
void DownLoadFile::mousePressEvent(QMouseEvent *event)
{

    if (event->type() == QEvent::MouseButtonPress && event->button() == Qt::RightButton)
    {
        tmp->move(mapFromGlobal(event->globalPos()));
        tmp->show();
    }
    __super::mousePressEvent(event);
}
