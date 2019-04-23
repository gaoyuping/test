

#ifndef CHIPIMAGE_H
#define CHIPIMAGE_H

#include <QColor>
#include <QGraphicsItem>
#include <QImage>

class ChipImage : public QGraphicsItem
{
public:
    ChipImage(int imaxx, int imaxy, QPointF lefttop, QPointF pos, std::vector<QPointF> data);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    //QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) Q_DECL_OVERRIDE;
    static double getsss();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
private:
    QImage * getMapByStep(int istep);
private:
    QPointF m_lefttop;
    QPointF m_pos;
    std::vector<QPointF> m_data;
    int m_ilod;
    int m_istep;
    QImage *m_image;
    QImage *m_image100;
    QImage *m_image10;
    QImage *m_image5;
    //QImage *m_image;
    //QImage *m_image;
    QColor color;
    QVector<QPointF> stuff;
    int m_x;
    int m_y;
};

#endif // CHIP_H
