#include "chipimage.h"
#include <QtWidgets>
#define ADD_SETP1 5

ChipImage::ChipImage(int imaxx, int imaxy, QPointF lefttop, QPointF pos, std::vector<QPointF> data)
{
    m_lefttop = lefttop;
    m_pos = pos;
    m_data = data;
    m_image = nullptr;
    m_image5 = nullptr;
    m_image10 = nullptr;
    m_image100 = nullptr;
    m_x = imaxx;
    m_y = imaxy;
    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptHoverEvents(true);
    m_istep = 10;
}

QRectF ChipImage::boundingRect() const
{
    if (m_x ==0 && m_y == 0)
    {
        return QRectF(0, 0, 10, 10);
    }
    return QRectF(0, 0, m_x, m_y);
}
#include "CMInfoProject.h"
void ChipImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QColor fillColor = (option->state & QStyle::State_Selected) ? color.dark(150) : color;
    const qreal lod = option->levelOfDetailFromTransform(painter->worldTransform());
    if (lod > 0.999999)
    {
        if (m_istep != 100)
        {
            m_istep = 100;
            if (!m_image100)
            {
                m_image100 = getMapByStep(100);
            }
            m_image = m_image100;
        }
    }
    else if (lod > 0.499999)
    {
        if (m_istep != 10)
        {
            m_istep = 10;
            if (!m_image10)
            {
                m_image10 = getMapByStep(10);
            }
            m_image = m_image10;
        }
    }
    else if (lod > 0.249999)
    {
        if (m_istep != 5)
        {
            m_istep = 5;
            if (!m_image5)
            {
                m_image5 = getMapByStep(5);
            }
            m_image = m_image5;
        }
    }

    if (m_image)
    {
        painter->drawImage(QRect(0, 0, m_x, m_y), *m_image, QRect(0, 0, m_image->width(), m_image->height()));
    }
    return;
}
double  ChipImage::getsss()
{
    static double i = 0.01;
    i +=0.17;
    if (i > 1)
    {
        i = 0.01;
    }
    return i;
}

void ChipImage::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void ChipImage::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void ChipImage::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}

QImage *ChipImage::getMapByStep(int istep)
{
    int imaxx = 0;
    int imaxy = 0;
    bool badd = true;
    std::vector<QPoint> m_datadraw;
    for (int i = 0; i < m_data.size(); i++)
    {
        QPoint  ret = CMInfoProject::PosToPoint(m_data[i], m_lefttop, istep);
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
    if (m_x == 0)
    {
        m_x = imaxx;
        m_y = imaxy;
    }
    QImage *tmp = new QImage(imaxx, imaxy, QImage::Format_ARGB32);
    if (tmp->isNull())
    {
        return nullptr;
    }
    
    //tmp->fill(QColor(255 * getsss(), 255 * getsss(), 255 * getsss()));
    QPainter painterimage(tmp);
    //painterimage.
    for (int i = 1; i < m_datadraw.size(); i++)
    {
        //painterimage.drawLine(m_datadraw[i - 1] + QPoint(10,10), m_datadraw[i] + QPoint(10,10));
        painterimage.drawLine(m_datadraw[i - 1], m_datadraw[i]);
    }
    return tmp;
}