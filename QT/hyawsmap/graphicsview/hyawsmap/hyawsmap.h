#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_hyawsmap.h"
#include <QPointF>
#include <QColor>
#include <QPushButton>

struct ST_XQ
{
    QPointF m_pos;
    QPointF m_topleftpoint;
    int m_imaxy;
    int m_imaxx;
    std::vector<QPointF> m_pointdata;
};
class hyawsmap : public QMainWindow
{
    Q_OBJECT

public:
    hyawsmap(QWidget *parent = Q_NULLPTR);
    void readdata();

    void makebufferdata();
    virtual bool eventFilter(QObject *watched, QEvent *event);
    void makeMapToImage();
    void showgraphicsview();
    void makeiamge();
public slots:
void slot_scale(int);
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
private:
    QColor getcolorByxy(int x, int y);
private:
    int m_i;
    Ui::hyawsmapClass ui;
    std::vector<ST_XQ> m_data1;
    std::vector<std::vector<QPoint>> m_datadraw;
    int **m_bufferdata;
    int m_imaxx;
    int m_imaxy;
    int m_beginx;
    int m_beginy;
    int m_beginoldx;
    int m_beginoldy;
    QImage *m_imagedata;
    QPoint mouseStartPoint;
    bool isDrag;
    bool m_init;
    int m_size;
    int m_step;
    bool m_update;
    QPointF m_topleft;
    QImage *m_tmp;
    QGraphicsScene *m_scene;
    QPushButton * m_btnsub;
    QPushButton * m_btnsub10;
    QPushButton * m_btnadd;
    QPushButton * m_btnadd10;
};
