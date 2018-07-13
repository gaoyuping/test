#ifndef MAKEAVATARWIDGET_H
#define MAKEAVATARWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QImage>

class MakeAvatarWidget : public QWidget
{
    Q_OBJECT

public:
    MakeAvatarWidget(QWidget *parent, int iAvatarWidth = 60, int iAvatarHeight = 60, int imaxwidth = 500, int imaxheight = 500);
    ~MakeAvatarWidget();

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void savepic(QString strpath = "");
protected:
    void paintEvent(QPaintEvent *event);
private:
    //input
    int m_iAvatarHeight;
    int m_iAvatarWidth;
private:
    QPixmap m_pixmap;
    QPixmap m_ellipse;
    QImage result_image;
    bool m_bpress;
    QPoint m_last;
    int m_paintX;
    int m_paintY;
    int m_iheight;
    int m_iwidth;
};

#endif // MAKEAVATARWIDGET_H
