#ifndef MAKEAVATARWIDGET_H
#define MAKEAVATARWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QImage>
enum LineType
{
    lineno,
    lineTop,
    lineButton,
    lineLeft,
    lineRight,
    lineTopleft,
    lineTopright,
    lineButtonleft,
    lineButtonright,
};

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
    void mouseNo(QMouseEvent*);
    void mouseTop(QMouseEvent*);
    void mouseButton(QMouseEvent*);
    void mouseLeft(QMouseEvent*);
    void mouseRight(QMouseEvent*);
    void mouseTopleft(QMouseEvent*);
    void mouseTopright(QMouseEvent*);
    void mouseButtonleft(QMouseEvent*);
    void mouseButtonright(QMouseEvent*);
    void makePic();
private:
    //input
    int m_iAvatarHeight;
    int m_iAvatarWidth;
private:
    QPixmap m_pixmap;
    QPixmap m_ellipse;
    QImage result_image;
    bool m_bpress;
    bool m_bchange;
    QPoint m_last;
    LineType m_mousetype;
    int m_paintX;
    int m_paintY;
    int m_iheight;
    int m_iwidth;
};

#endif // MAKEAVATARWIDGET_H
