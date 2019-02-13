#ifndef CMINFOPROJECT_H
#define CMINFOPROJECT_H

#include <QObject>
#include <QPointF>
//地图线条信息站点位置结构

class CMInfoProject
{
public:
    CMInfoProject();
    static QPoint PosToPoint(QPointF pos, QPointF m_MapLUPos, float m_nZoom = 1.0);
    static QPointF PointToPos(QPointF pnt, QPointF m_MapLUPos, float m_nZoom = 1.0);
};

#endif // CMINFOPROJECT_H
