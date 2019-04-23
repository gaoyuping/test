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
#define ADD_SETP 5
typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> microClock_type;
hyawsmap::hyawsmap(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_tmp = nullptr;
    m_step = 5;
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
    connect(m_btnsub, &QPushButton::released, [&](){
        m_size--;
        m_update = true;
        PosToPoint();
    });
    connect(m_btnadd, &QPushButton::released, [&](){
        m_size++;
        m_update = true;
        PosToPoint();
    });
    connect(m_btnsub10, &QPushButton::released, [&](){
        m_size /=2;
        if (m_size < 10)
        {
            m_size = 10;
        }
        m_update = true;
        PosToPoint();
    });
    connect(m_btnadd10, &QPushButton::released, [&](){
        m_size *= 2;
        if (m_size > 2000)
        {
            m_size = 2000;
        }
        m_update = true;
        PosToPoint();
    });
    float sss = 1.0;
    m_imagedata = nullptr;
    isDrag = false;
    installEventFilter(this);
    readdata();
    PosToPoint();
    m_beginx = 0;
    m_beginy = 0;
    //showgraphicsview();
}

QColor hyawsmap::getcolorByxy(int ix, int iy)
{
    if (m_bufferdata[ix][iy] == 1)
    {
        return QColor(0, 0, 0);
    }
    return QColor(255, 255, 255);
}
#include <iostream>
#include <fstream>

void hyawsmap::readdata()
{
    QFile mapfile("d:/map/countyregion.txt");
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
                m_data1.push_back(tmpdata);
                tmpdata.clear();
            }
        }
    }
    i = 0;
    microClock_type endtime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    qDebug() << "readdata " << endtime.time_since_epoch().count() - begintime.time_since_epoch().count();
}

void hyawsmap::PosToPoint()
{
    QPointF aaaa(121.282852, 40.043746);
    double x;
    double y;
    int ix=0;
    int iy=0;
    QPointF newaaaa;
    microClock_type begintime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    for (int i = 0; i < m_data1.size(); i++)
    {
        std::vector<QPoint> tmpdata;
        for (int j = 0; j < m_data1[i].size(); j++)
        {
            QPoint  ret = CMInfoProject::PosToPoint(m_data1[i][j], aaaa, m_size);
            if (ret.x() < ix)
            {
                newaaaa.setX(m_data1[i][j].x());
                ix = ret.x();
            }
            if (ret.y() < iy)
            {
                newaaaa.setY(m_data1[i][j].y());
                iy = ret.y();
            }
        }
    }
    int imaxx = 0;
    int imaxy = 0;
    std::vector<std::vector<QPoint>> datadraw;
    for (int i = 0; i < m_data1.size(); i ++)
    {
        std::vector<QPoint> tmpdata;
        for (int j = 0; j < m_data1[i].size(); j++)
        {
            QPoint  ret = CMInfoProject::PosToPoint(m_data1[i][j], newaaaa, m_size);
            tmpdata.push_back(ret);
            if (ret.x() > imaxx)
            {
                imaxx = ret.x();
            }
            if (ret.y() > imaxy)
            {
                imaxy = ret.y();
            }
        }
        if (tmpdata.size() > 0)
        {
            datadraw.push_back(tmpdata);
        }
    }
    if (m_imaxx)
    {
        if (m_beginx != 0 && m_beginx != 0)
        {
            m_beginx = width() / 2 - double(width() / 2 - m_beginx) / m_imaxx * imaxx;
            m_beginy = height() / 2 - double(height() / 2 - m_beginy) / m_imaxy * imaxy;
        }
    }
    m_datadraw.swap(datadraw);
    m_imaxy = imaxy;
    m_imaxx = imaxx;
    update();
    microClock_type endtime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    qDebug() << "PosToPoint " << endtime.time_since_epoch().count() - begintime.time_since_epoch().count();
    makeMapToImage();
}


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
    case QEvent::Wheel:
    {
        QWheelEvent * whellevent = (QWheelEvent *)event;
        if (whellevent->delta() > 0)
        {
            m_btnadd10->click();
        }
        else
        {
            m_btnsub10->click();
        }
        break;
    }
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
    makeiamge();
    View *view = new View("Graphicsview");
    connect(view, SIGNAL(signal_scale(double)), this, SLOT(slot_scale(double)), Qt::DirectConnection);
    m_scene = new QGraphicsScene;
    view->view()->setScene(m_scene);
    ui.verticalLayout->addWidget(view);
    int ix = 0;
    int iy = 0;
    int iiii = 0;
    //正负200范围

    for (int i = -100; i < 100; i++)
    {
        for (int j = -100; j < 100; j++)
        {
            iiii++;
            ix = i * ADD_SETP;
            iy = j * ADD_SETP;
            QGraphicsItem *item = new ChipImage(i, j, &m_tmp);
            item->setPos(QPointF(ix, iy));
            m_scene->addItem(item);
        }
    }
    iiii = 0;
}

void hyawsmap::makeiamge()
{
    QImage *tmp = new QImage(m_imaxx, m_imaxy, QImage::Format_ARGB32);
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

void hyawsmap::slot_scale(double i)
{
    if (m_step == 5)
    {
        if (i >= 1.5)
        {
            m_step = 10;
            m_size = 30;
            PosToPoint();
            makeiamge();
        }
    }
    else if (m_step == 10)
    {
        if (i < 1.5)
        {
            m_step = 5;
            m_size = 15;
            PosToPoint();
            makeiamge();
        }
    }
}

void hyawsmap::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    
    if (m_imagedata != nullptr)
    {
        microClock_type begintime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
        if (m_update == false && m_imagedata->width() >= width() && m_imagedata->height() >= height()/* && m_beginoldx == m_beginx && m_beginoldy == m_beginy*/)
        {
            p.drawImage(0, 0, *m_imagedata);
            microClock_type endtime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
            qDebug() << "repaintEvent " << endtime.time_since_epoch().count() - begintime.time_since_epoch().count();
            return;
        }
        m_update = false;
        QImage * tmp = new QImage(width(), height(), QImage::Format_ARGB32);
        tmp->fill(QColor(255, 255, 255));
        QPainter painterimage(tmp);
        for (int i = 0; i < m_datadraw.size(); i++)
        {
            for (int j = 1; j < m_datadraw[i].size(); j++)
            {
                if (m_datadraw[i][j - 1].x() < m_beginx && m_beginx < 0)
                {
                    continue;
                }
                if (m_datadraw[i][j - 1].y() < m_beginy && m_beginy < 0)
                {
                    continue;
                }
                if (m_datadraw[i][j - 1].x() >(width() + m_beginx) && m_beginx  > 0)
                {
                    continue;
                }

                if (m_datadraw[i][j - 1].y() >(width() + m_beginy) && m_beginy > 0)
                {
                    continue;
                }

                if (m_datadraw[i][j - 1].x() > (width() - m_beginx) && m_beginx < 0)
                {
                    continue;
                }

                if (m_datadraw[i][j - 1].y() > (width() - m_beginy) && m_beginy < 0)
                {
                    continue;
                }

                //painterimage.drawLine(m_datadraw[i][j - 1] + QPoint(m_beginx, m_beginy), m_datadraw[i][j] + QPoint(m_beginx, m_beginy));
            }
        }
        m_beginoldx = m_beginx;
        m_beginoldy = m_beginy;
        delete m_imagedata;
        m_imagedata = tmp;
        p.drawImage(0, 0, *m_imagedata);
        microClock_type endtime = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
        qDebug() << "redraw image paintEvent " << endtime.time_since_epoch().count() - begintime.time_since_epoch().count();
        return;
    }
    else
    {
        QImage * tmp = new QImage(width(), height(), QImage::Format_ARGB32);
        tmp->fill(QColor(255, 255, 255));
        QPainter painterimage(tmp);
        //painterimage.
        for (int i = 0; i < m_datadraw.size(); i++)
        {
            for (int j = 1; j < m_datadraw[i].size(); j++)
            {
                if (m_datadraw[i][j - 1].x() < m_beginx && m_beginx < 0)
                {
                    continue;
                }
                if (m_datadraw[i][j - 1].y() < m_beginy && m_beginy < 0)
                {
                    continue;
                }
                if (m_datadraw[i][j - 1].x() >(width() + m_beginx) && m_beginx > 0)
                {
                    continue;
                }

                if (m_datadraw[i][j - 1].y() >(width() + m_beginy) && m_beginy > 0)
                {
                    continue;
                }

                if (m_datadraw[i][j - 1].x() > (width() - m_beginx) && m_beginx < 0)
                {
                    continue;
                }

                if (m_datadraw[i][j - 1].y() >(width() - m_beginy) && m_beginy < 0)
                {
                    continue;
                }
                painterimage.drawLine(m_datadraw[i][j - 1] + QPoint(m_beginx, m_beginy), m_datadraw[i][j] + QPoint(m_beginx, m_beginy));
            }
        }
        m_beginoldx = m_beginx;
        m_beginoldy = m_beginy;
        m_imagedata = tmp;
        p.drawImage(0, 0, *m_imagedata);
    }
}

void hyawsmap::resizeEvent(QResizeEvent *event)
{
    m_btnadd10->move(width() / 2 - 10 - 5 - m_btnadd10->width() - m_btnadd->width(), 5);
    m_btnadd->move(width() / 2 - 5 - m_btnadd->width(), 5);
    m_btnsub10->move(width() / 2 + 10 + 5 + m_btnsub->width(), 5);
    m_btnsub->move(width() / 2 + 5, 5);
    __super::resizeEvent(event);
}