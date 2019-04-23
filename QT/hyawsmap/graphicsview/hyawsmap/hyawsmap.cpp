#include "hyawsmap.h"
#include <QFile>
#include <QDebug>
#include "View.h"
#include "Chip.h"
#include <QPainter>
#include <chrono>
#include <thread>
#include <QMessageBox>
#include "CMInfoProject.h"
#include <QMouseEvent>
#include "chipimage.h"
//#pragma comment(linker, "/STACK:1073741824")
#define _SETP_ 100
#include <qmath.h>
typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> microClock_type;
hyawsmap::hyawsmap(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_i = 0;
    m_tmp = nullptr;
    m_step = 10;
    m_size = 15;
    m_update = false;
    m_imaxx = 0;
    m_imaxy = 0;
    m_btnsub = new QPushButton(this);
    m_btnsub->setText("-");
    m_btnsub10 = new QPushButton(this);
    m_btnsub10->setText("-10");
    m_btnadd = new QPushButton(this);
    m_btnadd->setText("+");
    m_btnadd10 = new QPushButton(this);
    m_btnadd10->setText("+10");
    m_btnsub->hide();
    m_btnsub10->hide();
    m_btnadd->hide();
    m_btnadd10->hide();
//     for (int i = -20; i < 180; i++)
//     {
//         qreal scale = qPow(qreal(2), i/10);
//         qDebug() << "2^"<<i/10<<"="<< scale;
//     }
//     qDebug() << "-------------";
    for (int i = 0; i < 100; i++)
    {
        double dl = i / qreal(10);
        qreal scale = qPow(qreal(2), dl);
        qDebug() << "2^" << dl << "=" << scale *10;
    }
//     return;
    connect(m_btnsub, &QPushButton::released, [&](){
        m_size--;
        m_update = true;
        //PosToPoint();
    });
    connect(m_btnadd, &QPushButton::released, [&](){
        m_size++;
        m_update = true;
        //PosToPoint();
    });
    connect(m_btnsub10, &QPushButton::released, [&](){
        m_size /= 2;
        if (m_size < 10)
        {
            m_size = 10;
        }
        m_update = true;
        //PosToPoint();
    });
    connect(m_btnadd10, &QPushButton::released, [&](){
        m_size *= 2;
        if (m_size > 2000)
        {
            m_size = 2000;
        }
        m_update = true;
        //PosToPoint();
    });
    float sss = 1.0;
    m_imagedata = nullptr;
    isDrag = false;
    installEventFilter(this);
    readdata();
    m_beginx = 0;
    m_beginy = 0;
    showgraphicsview();
}

QColor hyawsmap::getcolorByxy(int ix, int iy)
{
    if (m_bufferdata[ix][iy] == 1)
    {
        return QColor(0, 0, 0);
    }
    return QColor(255, 255, 255);
}
#include <QFileDialog>
void hyawsmap::readdata()
{
    QFileDialog dlg;
    QString str = dlg.getOpenFileName();
    QFile mapfile(str);
    if (!mapfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Can't open the file!" << endl;
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("运行目录未找到china.mif文件"));
        return;
    }
    int i = 0;
    std::vector<QPointF> tmpdata;
    //std::vector<std::vector<QPointF*>> m_data111;
    microClock_type begintime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    QPointF topleft(121.282852, 40.043746);
    while (!mapfile.atEnd()) {
        QByteArray line = mapfile.readLine();
        QString str(line);
        str = str.trimmed();
        int iindex = str.indexOf("  ");
        while (str.indexOf("  ") != -1)
        {
            str = str.replace("  ", " ");
        }
        if (str.indexOf(' ') != -1)
        {
            QStringList strlist = str.split(' ');
            if (strlist.size() == 2)
            {
                QPointF sss(strlist[0].toFloat(), strlist[1].toFloat());
                tmpdata.push_back(sss);
            }
        }
        else
        {
            if (tmpdata.size() > 0)
            {
                QPointF newaaaa = tmpdata[0];
                if (!m_init)
                {
                    m_init = true;
                    topleft = newaaaa;
                }
                bool bchang = false;
                int ix = 0;
                int iy = 0;
                int ix1 = 0;
                int iy1 = 0;
                changerebegin:
                for (int i = 1; i < tmpdata.size(); i++)
                {
                    QPoint  ret = CMInfoProject::PosToPoint(tmpdata[i], newaaaa, _SETP_);
                    if (ret.x() < 0 || ret.y() < 0)
                    {
                        int iii = 0;
                    }
                    if (ret.x() <= ix && ret.x())
                    {
                        ix = ret.x();
                        newaaaa.setX(tmpdata[i].x());
                        bchang = true;
                    }
                    if (ret.y() <= iy && ret.y())
                    {
                        iy = ret.y();
                        newaaaa.setY(tmpdata[i].y());
                        bchang = true;
                    }
                    ret = CMInfoProject::PosToPoint(tmpdata[i], topleft, _SETP_);
                    if (ret.x() <= ix1 && ret.x())
                    {
                        ix1 = ret.x();
                        topleft.setX(tmpdata[i].x());
                    }
                    if (ret.y() <= iy1 && ret.y())
                    {
                        iy1 = ret.y();
                        topleft.setY(tmpdata[i].y());
                    }
                }
                if (bchang)
                {
                    bchang = false;
                    goto changerebegin;
                }

                int imaxx = 0;
                int imaxy = 0;
                bool badd = true;
                std::vector<QPoint> m_datadraw;
                for (int i = 0; i < tmpdata.size(); i++)
                {
                    QPoint  ret = CMInfoProject::PosToPoint(tmpdata[i], newaaaa, _SETP_);
                    badd = true;
                    for (int i = 0; i < m_datadraw.size(); i++)
                    {
                        if (m_datadraw[i] == ret)
                        {
                            badd = false;
                            break;
                        }
                    }
                    if (!badd)
                    {
                        continue;
                    }
                    m_datadraw.push_back(ret);
                    if (imaxx < ret.x())
                    {
                        imaxx = ret.x();
                    }
                    if (imaxy < ret.y())
                    {
                        imaxy = ret.y();
                    }
                }
                if (imaxx <1 || imaxy < 1)
                {
                    imaxx = 0;
                }
                ST_XQ sttmp;
                sttmp.m_topleftpoint = newaaaa;
                sttmp.m_imaxx = imaxx;
                sttmp.m_imaxy = imaxy;
                sttmp.m_pointdata.swap(tmpdata);
                m_data1.push_back(sttmp);
                tmpdata.clear();
                i++;
                if (i > 1)
                {
                    //break;
                }
            }
        }
    }
    mapfile.close();
    i = 0;
    for (int i = 0; i < m_data1.size(); i++)
    {
        m_data1[i].m_pos = topleft;
    }
    microClock_type endtime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    qDebug() << "readdata " << endtime.time_since_epoch().count() - begintime.time_since_epoch().count();
}
// 
// void hyawsmap::PosToPoint()
// {
//     microClock_type begintime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
//     int imaxx = 0;
//     int imaxy = 0;
//     std::vector<std::vector<QPoint>> datadraw;
//     for (int i = 0; i < m_data1.size(); i ++)
//     {
//         std::vector<QPoint> tmpdata;
//         for (int j = 0; j < m_data1[i].size(); j++)
//         {
//             QPoint  ret = CMInfoProject::PosToPoint(m_data1[i][j], m_topleft, m_size);
//             tmpdata.push_back(ret);
//             if (ret.x() > imaxx)
//             {
//                 imaxx = ret.x();
//             }
//             if (ret.y() > imaxy)
//             {
//                 imaxy = ret.y();
//             }
//         }
//         if (tmpdata.size() > 0)
//         {
//             datadraw.push_back(tmpdata);
//         }
//     }
//     if (m_imaxx)
//     {
//         if (m_beginx != 0 && m_beginx != 0)
//         {
//             m_beginx = width() / 2 - double(width() / 2 - m_beginx) / m_imaxx * imaxx;
//             m_beginy = height() / 2 - double(height() / 2 - m_beginy) / m_imaxy * imaxy;
//         }
//     }
//     m_datadraw.swap(datadraw);
//     m_imaxy = imaxy;
//     m_imaxx = imaxx;
//     update();
//     microClock_type endtime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
//     qDebug() << "PosToPoint " << endtime.time_since_epoch().count() - begintime.time_since_epoch().count();
//     makeMapToImage();
// }


void hyawsmap::makebufferdata()
{
    m_bufferdata = new int*[m_imaxx+1];
    for (int i = 0; i < m_imaxx+1; i++)
    {
        m_bufferdata[i] = new int[m_imaxy+1];
    }
    for (int i = 0; i < m_datadraw.size(); i++)
    {
        for (int j = 0; j < m_datadraw[i].size(); j++)
        {
            int ix = m_datadraw[i][j].x();
            int iy = m_datadraw[i][j].y();
            m_bufferdata[ix][iy] = 1;
        }
    }
}

bool hyawsmap::eventFilter(QObject *watched, QEvent *event)
{
    QMouseEvent* mevent = (QMouseEvent*)event;
    switch (mevent->type())
    {
    case QEvent::MouseButtonPress:
        if (Qt::LeftButton == mevent->button())
        {
            isDrag = true;
            //获得鼠标的初始位置
            mouseStartPoint = mevent->globalPos();
        }
        break;
    case QEvent::MouseMove:
        if (isDrag)
        {
            //获得鼠标移动的距离
            QPoint distance = mevent->globalPos() - mouseStartPoint;
            mouseStartPoint = mevent->globalPos();
            qDebug() << distance;
            m_beginx += distance.x();
            m_beginy += distance.y();
            update();
        }
        break;
    case QEvent::MouseButtonRelease:
        if (Qt::LeftButton == mevent->button())
        {
            isDrag = false;
        }
        break;
    default:
        //qDebug() << mevent->type();
        break;
    }

    return QMainWindow::eventFilter(watched, event);
}

void hyawsmap::makeMapToImage()
{
    return;
    QImage tmp(m_imaxx, m_imaxy, QImage::Format_ARGB32);
    tmp.fill(QColor(255, 255, 255));
    QPainter painterimage(&tmp);
    //painterimage.
    for (int i = 0; i < m_datadraw.size(); i++)
    {
        for (int j = 1; j < m_datadraw[i].size(); j++)
        {
            painterimage.drawLine(m_datadraw[i][j - 1], m_datadraw[i][j]);
        }
    }
    QString strname;
    strname = "mapimage_";
    strname.append(QString::number(m_size)).append(".jpg");
    tmp.save(strname);
    QString strname1;
    strname1 = "mapimage_";
    strname1.append(QString::number(m_size)).append(".png");
    tmp.save(strname1);
}

void hyawsmap::showgraphicsview()
{
    View *view = new View("Graphicsview");
    connect(view, SIGNAL(signal_scale(int)), this, SLOT(slot_scale(int)));
    m_scene = new QGraphicsScene;
    view->view()->setScene(m_scene);
    ui.verticalLayout->addWidget(view);

    for (int i = 0; i < m_data1.size(); i++)
    {
        bool badd = true;
        std::vector<QPoint> m_datadraw;
        for (int j = 0; j < m_data1[i].m_pointdata.size(); j++)
        {
            QPoint  ret = CMInfoProject::PosToPoint(m_data1[i].m_pointdata[j], m_data1[i].m_topleftpoint, _SETP_);
            badd = true;
            for (int ii = 0; ii < m_datadraw.size(); ii++)
            {
                if (m_datadraw[ii] == ret)
                {
                    badd = false;
                    break;
                }
            }
            if (!badd)
            {
                continue;
            }
            m_datadraw.push_back(ret);
        }
        QPainterPath path;
        path.moveTo(m_datadraw[0]);
        for (int i = 1; i < m_datadraw.size(); i++)
        {
            path.lineTo(m_datadraw[i]);
        }
        QGraphicsPolygonItem* item = new QGraphicsPolygonItem;
        item->setPolygon(path.toFillPolygon());
        QPen pen;
        pen.setWidth(1);
        pen.setColor(QColor(100,255,100));
        item->setPen(pen);
        //item->setFlag(QGraphicsItem::ItemIsMovable, true);
        //item->setFlag(QGraphicsItem::ItemIsSelectable, true);

        //QGraphicsItem *item = new ChipImage(m_data1[i].m_imaxx, m_data1[i].m_imaxy, m_data1[i].m_topleftpoint, m_data1[i].m_pos, m_data1[i].m_pointdata);
        QPoint  ret = CMInfoProject::PosToPoint(m_data1[i].m_topleftpoint, m_data1[i].m_pos, _SETP_);
        item->setPos(ret);
        m_scene->addItem(item);
    }
    return;
}

void hyawsmap::makeiamge()
{
    if (m_imaxx == 0)
    {
        return;
    }
    QImage *tmp = new QImage(m_imaxx, m_imaxy, QImage::Format_ARGB32);
    if (tmp->isNull())
    {
        return;
    }
    tmp->fill(QColor(255, 255, 255));
    do
    {
        QPainter painterimage(tmp);
        //painterimage.
        for (int i = 0; i < m_datadraw.size(); i++)
        {
            for (int j = 1; j < m_datadraw[i].size(); j++)
            {
                painterimage.drawLine(m_datadraw[i][j - 1], m_datadraw[i][j]);
            }
        }
    } while (0);

    QImage *tmp1 = new QImage(200 * m_step, 200 * m_step, QImage::Format_ARGB32);
    if (tmp1->isNull())
    {
        return;
    }
    tmp1->fill(QColor(255, 255, 255));
    do
    {
        QPainter painterimage(tmp1);
        painterimage.drawImage((200 * m_step - m_imaxx) / 2, (200 * m_step - m_imaxy) / 2, *tmp);
    } while (0);
    if (m_tmp)
    {
        delete m_tmp;
    }
    m_tmp = tmp1;
}

void hyawsmap::slot_scale(int i)
{
    return;
    if (i != m_i)
    {
        m_i = i;
        m_step = qPow(qreal(2), m_i - 1);
        m_step *= 10;
        m_size = m_step;
        //PosToPoint();
        makeiamge();
    }
}

void hyawsmap::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void hyawsmap::resizeEvent(QResizeEvent *event)
{
    m_btnadd10->move(width() / 2 - 10 - 5 - m_btnadd10->width() - m_btnadd->width(), 5);
    m_btnadd->move(width() / 2 - 5 - m_btnadd->width(), 5);
    m_btnsub10->move(width() / 2 + 10 + 5 + m_btnsub->width(), 5);
    m_btnsub->move(width() / 2 + 5, 5);
    __super::resizeEvent(event);
}