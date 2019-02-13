#include "CMInfoProject.h"

CMInfoProject::CMInfoProject()
{

}

//--------------------------------------------------------------------------//
// 函数名称： PosToPoint                                                    //
// 说明    ： 经纬度坐标转换到屏幕坐标（根据放大倍数和地图左上角经纬度计算）//
// 入口参数： CPoint pos -- 经纬度                                     //
// 返回值  ： CPoint  -- 屏幕坐标                                           //
//--------------------------------------------------------------------------//
QPoint CMInfoProject::PosToPoint(QPointF pos, QPointF m_MapLUPos, float m_nZoom)
{
    QPoint result;

    float x=0,y=0;
    x =  (pos.x() - m_MapLUPos.x()) *m_nZoom;
    y = (m_MapLUPos.y() - pos.y()) * m_nZoom;
    result.setX(x);
    result.setY(y);
    return  (result);//ProjToWorld//ProjToWorld
}
//--------------------------------------------------------------------------//
// 函数名称： PointToPos                                                    //
// 说明    ： 屏幕坐标转换到经纬度坐标（根据放大倍数和地图左上角经纬度计算）//
// 入口参数： CPoint pnt -- 屏幕坐标                                        //
// 返回值  ： CPoint  -- 经纬度                                             //
//--------------------------------------------------------------------------//
QPointF CMInfoProject::PointToPos(QPointF pnt, QPointF m_MapLUPos, float m_nZoom)
{
    QPointF result;

    result.setX((m_MapLUPos.x() +(float)(pnt.x() )/m_nZoom));   ;
    result.setY((m_MapLUPos.y() -(float)(pnt.y() )/m_nZoom));
    return  (result);//WorldToProj
}
