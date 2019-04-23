#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>
#include <QtCore/QDir>

#include <QThread>
#include <QPainter>
#include <QInputDialog>
#include <QtMath>

#include <QMouseEvent>
#include <QSettings>

#include <QSettings>
#include <QString>
#include <QDebug>

#include<iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    videoPath = QString::fromStdString(R"(D:\ffmpeg\a.mp4)");
    //videoPath = QString::fromStdString(R"(D:\ffmpeg\b.mp4)");
    //videoPath = QString::fromStdString(R"(D:\ffmpeg\768x576.avi)");
    //videoPath = QString::fromStdString(R"(D:\ffmpeg\c.wmv)");
    
    mPlayer = new VideoPlayer(videoPath);
    connect(mPlayer, SIGNAL(sig_GetOneFrame(QImage, double)), this, SLOT(slotGetOneFrame(QImage, double)));
    connect(mPlayer, SIGNAL(sig_GetOneFramewh(int, int, double)), this, SLOT(slotGetOneFramewh(int, int, double)));
    
    connect(ui->Open_red,&QAction::triggered,this,&MainWindow::slotOpenRed);
    connect(ui->Close_Red,&QAction::triggered,this,&MainWindow::slotCloseRed);

    mPlayer->startPlay();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //painter.setBrush(QColor(0,0,0,0));
    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, this->width(), this->height()); //先画成白色

    if (mImage.size().width() <= 0) return;

    //将图像按比例缩放成和窗口一样大小
    QImage img = mImage.scaled(this->size(), Qt::KeepAspectRatio);

    int x = this->width() - img.width();
    int y = this->height() - img.height();

    x /= 2;
    y /= 2;

    painter.drawImage(QPoint(x,y),img); //画出图像
    painter.setPen(Qt::white);
    painter.drawText(QRect(x + img.width() - 200, y + img.height() - 20, 200, 20), Qt::AlignRight, m_currenttime + QStringLiteral("/") + m_totalduration);

}
static int g_icount = 0;
void MainWindow::slotGetOneFrame(QImage img, double currenttime)
{
    mImage = img;
    m_currenttime = QString::number(currenttime, 'f', 2);
    update(); //调用update将执行 paintEvent函数
    g_icount++;
    //qDebug() << "updata time :" << currenttime;
}

void MainWindow::slotGetOneFramewh(int iw, int ih, double totalduration)
{
    m_totalduration = QString::number(totalduration, 'f', 2);
    resize(iw, ih);
}
//小窗口显示
void MainWindow::slotGetRFrame(QImage img)
{
    R_mImage = img;
    update(); //调用update将执行 paintEvent函数
}
//显示图像红色通道,2017.8.12---lizhen
bool MainWindow::slotOpenRed()
{
    open_red=true;
    return open_red;
}
//关闭图像红色通道，2017.8.12
bool MainWindow::slotCloseRed()
{
    open_red=false;
    return open_red;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    qDebug() << "QKeyEvent:" <<key;
    if(key == Qt::Key_A){
        vWindow = new videowindow;
        vWindow->setAttribute(Qt::WA_DeleteOnClose,true);
        vWindow->showFullScreen();
    }

}

