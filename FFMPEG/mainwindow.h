#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QImage>
#include <QPaintEvent>
#include <QWidget>
#include <QtDebug>

#include <QtConcurrent/qtconcurrentrun.h>
#include "videoplayer.h"
#include "localvideoplayer.h"
#include "videowindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    VideoPlayer *mPlayer;
    LocalVideoPlayer *mLocalPlayer;

    QImage mImage;
    QString m_currenttime;
    QString m_totalduration;
    QImage R_mImage;

    QString url;

    videowindow *vWindow;

    bool open_red=false;
    void keyPressEvent(QKeyEvent *event);

    QString videoPath;

private slots:
void slotGetOneFrame(QImage img, double);
    void slotGetOneFramewh(int, int, double);
    void slotGetRFrame(QImage img);
    bool slotOpenRed();
    bool slotCloseRed();
};

#endif // MAINWINDOW_H
