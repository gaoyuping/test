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
    m_bchange = false;
    m_mousetype = lineno;
    setMouseTracking(true);
    QString strpath;// = QDir::currentPath();
    //strpath = QCoreApplication::applicationDirPath();
    strpath.append("F:/5.jpg");
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

    makePic();
}

MakeAvatarWidget::~MakeAvatarWidget()
{

}

void MakeAvatarWidget::mousePressEvent(QMouseEvent *event)
{
    if (lineno == m_mousetype)
    {
        setCursor(Qt::ClosedHandCursor);
    }
    m_last = event->pos();
    m_bpress = true;
    QWidget::mousePressEvent(event);
}

void MakeAvatarWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_bpress = false;
    QWidget::mouseReleaseEvent(event);
}
#define LINEWIDTH 2
#define LINEWIDTHH LINEWIDTH/2
#define CORNERIDTHH 5
#define CORNERIDTHHH 2
void MakeAvatarWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bpress)
    {
        switch (m_mousetype)
        {
            case lineno:
                mouseNo(event);
                break;
            case lineTop:
                mouseTop(event);
            case lineButton:
                mouseButton(event);
                break;
            case lineLeft:
                mouseLeft(event);
                break;
            case lineRight:
                mouseRight(event);
                break;
            case lineTopleft:
                mouseTopleft(event);
                break;
            case lineTopright:
                mouseTopright(event);
                break;
            case lineButtonleft:
                mouseButtonleft(event);
                break;
            case lineButtonright:
                mouseButtonright(event);
                break;
            default:
                break;
        }
    }
    else
    {
        int itopx = m_iwidth / 2 - m_iAvatarWidth / 2;
        int itopy = m_iheight / 2 - m_iAvatarHeight / 2;
        int ibuttonx = m_iwidth / 2 + m_iAvatarWidth / 2;
        int ibuttony = m_iwidth / 2 + m_iAvatarHeight / 2;

        QRect recttop(itopx + LINEWIDTHH, itopy + LINEWIDTHH, m_iAvatarWidth - LINEWIDTH, LINEWIDTH);
        QRect rectbutton(itopx + LINEWIDTHH, ibuttony, m_iAvatarWidth - LINEWIDTH, LINEWIDTH);
        QRect rectleft(itopx + LINEWIDTHH, itopy + LINEWIDTHH, LINEWIDTH, m_iheight - LINEWIDTH);
        QRect rectright(ibuttonx, itopy - LINEWIDTHH, LINEWIDTH, m_iheight - LINEWIDTH);

        QRect recttopleft(itopx - CORNERIDTHHH, itopy - CORNERIDTHHH, CORNERIDTHH, CORNERIDTHH);
        QRect recttopright(ibuttonx - CORNERIDTHHH, itopy - CORNERIDTHHH, CORNERIDTHH, CORNERIDTHH);
        QRect rectbuttonleft(itopx - CORNERIDTHHH, ibuttony - CORNERIDTHHH, CORNERIDTHH, CORNERIDTHH);
        QRect rectbuttonright(ibuttonx - CORNERIDTHHH, ibuttony - CORNERIDTHHH, CORNERIDTHH, CORNERIDTHH);
        
        if (true == recttopleft.contains(mapFromGlobal(event->globalPos())))
        {
            m_mousetype = lineTopleft;
            setCursor(Qt::SizeFDiagCursor);
        }
        else if (true == recttopright.contains(mapFromGlobal(event->globalPos())))
        {
            m_mousetype = lineTopright;
            setCursor(Qt::SizeBDiagCursor);
        }
        else if (true == rectbuttonleft.contains(mapFromGlobal(event->globalPos())))
        {
            m_mousetype = lineButtonleft;
            setCursor(Qt::SizeBDiagCursor);
        }
        else if (true == rectbuttonright.contains(mapFromGlobal(event->globalPos())))
        {
            m_mousetype = lineButtonright;
            setCursor(Qt::SizeFDiagCursor);
        }
        else if (true == recttop.contains(mapFromGlobal(event->globalPos())))
        {
            m_mousetype = lineTop;
            setCursor(Qt::SizeVerCursor);
        }
        else if (true == rectbutton.contains(mapFromGlobal(event->globalPos())))
        {
            m_mousetype = lineButton;
            setCursor(Qt::SizeVerCursor);
        }
        else if (true == rectleft.contains(mapFromGlobal(event->globalPos())))
        {
            m_mousetype = lineLeft;
            setCursor(Qt::SizeHorCursor);
        }
        else if (true == rectright.contains(mapFromGlobal(event->globalPos())))
        {
            m_mousetype = lineRight;
            setCursor(Qt::SizeHorCursor);
        }
        else
        {
            m_mousetype = lineno;
            setCursor(Qt::OpenHandCursor);
        }
    }
    if (m_bpress)
    {
        update();
    }
    QWidget::mouseMoveEvent(event);
}
#include <QMessageBox>
#include <QIcon>

void MakeAvatarWidget::savepic(QString strpath)
{
    if (strpath.isEmpty())
    {
        strpath = QCoreApplication::applicationDirPath();
        strpath.append("/../../outpic.png");
    }

    QPixmap outpic = m_pixmap.copy((width() - m_iAvatarWidth) / 2 - m_paintX, (height() - m_iAvatarHeight) / 2 - m_paintY, m_iAvatarWidth, m_iAvatarHeight);
    QIcon sss1(outpic);
    
    outpic.save(strpath);
    QMessageBox::information(this, "title", QStringLiteral("保存完成 保存路径").append(strpath));
}
void MakeAvatarWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawImage(QPoint(m_paintX, m_paintY), m_pixmap.toImage());

    if (m_bchange)
    {
        makePic();
    }
    p.drawImage(QPoint(0, 0), result_image);
}

void MakeAvatarWidget::mouseNo(QMouseEvent *event)
{
    if (m_paintX + event->pos().x() - m_last.x() > (width() - m_iAvatarWidth) / 2)
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
}

void MakeAvatarWidget::mouseTop(QMouseEvent *event)
{
    int ichange = ((event->pos().y() - m_last.y()))*2;
    if (m_iAvatarHeight - ichange > 60 && m_iAvatarHeight - ichange < 500 - 2)
    {
        m_iAvatarHeight = m_iAvatarHeight - ichange;
        m_iAvatarWidth = m_iAvatarWidth - ichange;
        m_bchange = true;
    }
    m_last = event->pos();
}

void MakeAvatarWidget::mouseButton(QMouseEvent *event)
{
    int ichange = ((event->pos().y() - m_last.y())) * 2;
    if (m_iAvatarHeight + ichange > 60 && m_iAvatarHeight + ichange < 500 - 2)
    {
        m_iAvatarHeight = m_iAvatarHeight + ichange;
        m_iAvatarWidth = m_iAvatarWidth + ichange;
        m_bchange = true;
    }
    m_last = event->pos();
}

void MakeAvatarWidget::mouseLeft(QMouseEvent *event)
{
    int ichange = ((event->pos().x() - m_last.x())) * 2;
    if (m_iAvatarHeight - ichange > 60 && m_iAvatarHeight - ichange < 500 - 2)
    {
        m_iAvatarHeight = m_iAvatarHeight - ichange;
        m_iAvatarWidth = m_iAvatarWidth - ichange;
        m_bchange = true;
    }
    m_last = event->pos();
}

void MakeAvatarWidget::mouseRight(QMouseEvent *event)
{
    int ichange = ((event->pos().x() - m_last.x())) * 2;
    if (m_iAvatarHeight + ichange > 60 && m_iAvatarHeight + ichange < 500 - 2)
    {
        m_iAvatarHeight = m_iAvatarHeight + ichange;
        m_iAvatarWidth = m_iAvatarWidth + ichange;
        m_bchange = true;
    }
    m_last = event->pos();
}

void MakeAvatarWidget::mouseTopleft(QMouseEvent *event)
{
    mouseTop(event);
}

void MakeAvatarWidget::mouseTopright(QMouseEvent *event)
{
    mouseTop(event);
}

void MakeAvatarWidget::mouseButtonleft(QMouseEvent *event)
{
    mouseButton(event);
}

void MakeAvatarWidget::mouseButtonright(QMouseEvent *event)
{
    mouseButton(event);
}

void MakeAvatarWidget::makePic()
{
    result_image = QImage(m_iwidth, m_iwidth, QImage::Format_ARGB32_Premultiplied);
    result_image.fill(0);
    QPainter painter(&result_image);
    QPainterPath path;
    //添加椭圆
    path.addEllipse(QPoint((m_iwidth) / 2, (m_iheight) / 2), m_iAvatarWidth / 2, m_iAvatarHeight / 2);
    path.addRect(0, 0, m_iwidth, m_iheight);
    //设置填充
    painter.setBrush(QBrush(QColor(50, 255, 0, 50)));
    painter.setPen(QPen(QColor(50, 255, 0, 50)));
    painter.drawPath(path);


    QPainterPath path1;
    //添加椭圆
    path1.addRect((m_iwidth) / 2 - m_iAvatarWidth / 2 - 1, (m_iheight) / 2 - m_iAvatarHeight / 2 - 1, m_iAvatarWidth + 2, m_iAvatarHeight + 2);
    path1.addRect((m_iwidth) / 2 - m_iAvatarWidth / 2, (m_iheight) / 2 - m_iAvatarHeight / 2, m_iAvatarWidth, m_iAvatarHeight);
    //设置填充
    painter.setPen(QPen(QColor(255, 0, 0, 255)));
    painter.drawPath(path1);
    QPen penline;
    penline.setColor(QColor(255, 0, 0, 255));
    penline.setStyle(Qt::DashLine);
    painter.setPen(penline);
    painter.drawLine(QPoint((m_iwidth - m_iAvatarWidth) / 2 - 1, (m_iheight - m_iAvatarHeight) / 2 + m_iAvatarHeight / 3), QPoint((m_iwidth + m_iAvatarWidth) / 2 - 1, (m_iheight - m_iAvatarHeight) / 2 + m_iAvatarHeight / 3));

    painter.drawLine(QPoint((m_iwidth - m_iAvatarWidth) / 2 - 1, (m_iheight - m_iAvatarHeight) / 2 + m_iAvatarHeight *2 / 3), QPoint((m_iwidth + m_iAvatarWidth) / 2 - 1, (m_iheight - m_iAvatarHeight) / 2 + m_iAvatarHeight * 2 / 3));

    painter.drawLine(QPoint((m_iwidth - m_iAvatarWidth) / 2 - 1 + m_iAvatarHeight / 3, (m_iheight - m_iAvatarHeight) / 2), QPoint((m_iwidth - m_iAvatarWidth) / 2 - 1 + m_iAvatarHeight / 3, (m_iheight + m_iAvatarHeight) / 2));

    painter.drawLine(QPoint((m_iwidth - m_iAvatarWidth) / 2 - 1 + m_iAvatarHeight *2 / 3, (m_iheight - m_iAvatarHeight) / 2), QPoint((m_iwidth - m_iAvatarWidth) / 2 - 1 + m_iAvatarHeight *2 / 3, (m_iheight + m_iAvatarHeight) / 2));
}
