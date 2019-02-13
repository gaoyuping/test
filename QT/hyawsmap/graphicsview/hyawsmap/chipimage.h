

#ifndef CHIPIMAGE_H
#define CHIPIMAGE_H

#include <QColor>
#include <QGraphicsItem>
#include <QImage>

class ChipImage : public QGraphicsItem
{
public:
    ChipImage(int x, int y, QImage** image);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    //QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

private:
    int x;
    int y;
    int m_istep;
    QImage **m_image;
    QColor color;
    QVector<QPointF> stuff;
};

#endif // CHIP_H
