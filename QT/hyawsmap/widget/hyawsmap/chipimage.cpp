#include "chipimage.h"
#include <QtWidgets>
#define ADD_SETP1 5

ChipImage::ChipImage(int x, int y, QImage** image)
{
    this->x = x;
    this->y = y;
    m_image = image;
    //setZValue((x + y) % 2);

    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptHoverEvents(true);
    m_istep = 5;
}

QRectF ChipImage::boundingRect() const
{
    return QRectF(0, 0, 5, 5);
}

void ChipImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QColor fillColor = (option->state & QStyle::State_Selected) ? color.dark(150) : color;
    const qreal lod = option->levelOfDetailFromTransform(painter->worldTransform());
    if (lod > 1.5)
    {
        
        if (m_istep == 5)
        {
            m_istep = 10;
            //setPos(QPointF(x * m_istep, y * m_istep));
        }
    }
    else
    {
        if (m_istep == 10)
        {
            m_istep = 5;
            //setPos(QPointF(x * m_istep, y * m_istep));
        }
    }
    if (*m_image)
    {
        painter->drawImage(QRect(0, 0, 5, 5), **m_image, QRect((x + 100) * m_istep, (y + 100) * m_istep, m_istep, m_istep));
    }
    return;
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
