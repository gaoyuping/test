#include "MakeAvatarWidget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QDir>
#include <QCoreApplication>

MakeAvatarWidget::MakeAvatarWidget(QWidget *parent, int iAvatarWidth, int iAvatarHeight, int imaxwidth, int imaxheight)
    : QWidget(parent), m_iAvatarWidth(iAvatarWidth), m_iAvatarHeight(iAvatarHeight)
{
    m_bpress = false;
    m_last.setX(0);
    m_last.setY(0);
    m_paintX = 0;
    m_paintY = 0;

    QString strpath =  QDir::currentPath();
    strpath = QCoreApplication::applicationDirPath();
    strpath.append("/../../1.png");
    m_pixmap.load(strpath);

    m_iwidth = m_pixmap.width();
    if (m_iwidth > imaxwidth)
    {
        m_iwidth = imaxwidth;
    }
    m_iheight = m_pixmap.height();
    if (m_iheight > imaxheight)
    {
        m_iheight = imaxheight;
    }
    setFixedSize(m_iwidth, m_iheight);

    result_image = QImage(m_iwidth, m_iwidth, QImage::Format_ARGB32_Premultiplied);
    result_image.fill(0);
    QPainter painter(&result_image);
    QPainterPath path;
    //添加椭圆
    path.addEllipse(QPoint((m_iwidth) / 2, (m_iheight) / 2), m_iAvatarWidth/2, m_iAvatarHeight/2);
    path.addRect(0, 0, m_iwidth, m_iheight);
    //设置填充
    painter.setBrush(QBrush(QColor(50, 255, 0, 50)));
    painter.setPen(QPen(QColor(50, 255, 0, 50)));
    painter.drawPath(path);
}

MakeAvatarWidget::~MakeAvatarWidget()
{

}

void MakeAvatarWidget::mousePressEvent(QMouseEvent *event)
{
    m_last = event->pos();
    m_bpress = true;
    QWidget::mousePressEvent(event);
}

void MakeAvatarWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_bpress = false;
    QWidget::mouseReleaseEvent(event);
}

void MakeAvatarWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_paintX + event->pos().x() - m_last.x() > (width() - m_iAvatarWidth)/2)
    {
        m_paintX = (width() - m_iAvatarWidth) / 2;
    }
    else if (m_paintX + event->pos().x() - m_last.x() < -(m_pixmap.width() - m_iwidth) - (width() - m_iAvatarWidth) / 2)
    {
        m_paintX = -(m_pixmap.width() - m_iwidth) - (width() - m_iAvatarWidth) / 2;
    }
    else
    {
        m_paintX = m_paintX + event->pos().x() - m_last.x();
    }

    if (m_paintY + event->pos().y() - m_last.y() > (height() - m_iAvatarHeight) / 2)
    {
        m_paintY = (height() - m_iAvatarHeight) / 2;
    }
    else if (m_paintY + event->pos().y() - m_last.y() < -(m_pixmap.height() - m_iheight) - (height() - m_iAvatarHeight) / 2)
    {
        m_paintY = -(m_pixmap.height() - m_iheight) - (height() - m_iAvatarHeight) / 2;
    }
    else
    {
        m_paintY = m_paintY + event->pos().y() - m_last.y();
    }

    m_last = event->pos();
    QWidget::mouseMoveEvent(event);
    update();
}
#include <QMessageBox>
void MakeAvatarWidget::savepic(QString strpath)
{
    if (strpath.isEmpty())
    {
        strpath = QCoreApplication::applicationDirPath();
        strpath.append("/../../outpic.png");
    }

    //QPixmap outpic = m_pixmap.copy(width() - m_paintX, height() - m_paintY, m_iAvatarWidth, m_iAvatarHeight);
    QPixmap outpic = m_pixmap.copy((width() - m_iAvatarWidth) / 2 - m_paintX, (height() - m_iAvatarHeight) / 2 - m_paintY, m_iAvatarWidth, m_iAvatarHeight);
    outpic.save(strpath);
    QMessageBox::information(this, "title", QStringLiteral("保存完成 保存路径").append(strpath));
}
void MakeAvatarWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawImage(QPoint(m_paintX, m_paintY), m_pixmap.toImage());


    
    p.drawImage(QPoint(0, 0), result_image);
}
