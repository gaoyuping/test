#pragma once

#include "QbaseWidget.h"
#include <QPushButton>

class QLayerDrawer : public QbaseWidget
{
    Q_OBJECT

public:
    QLayerDrawer(QWidget *parent);
    ~QLayerDrawer();
    QPushButton m_btntitle;//标题
    std::vector<QPushButton*> m_veccontent;//元素集合

signals:
    void signal_showcontent();
public:
    void setTitleTxt(QString);
    QString getTitleTxt();
    void addContent(QString, int icontent = -1);
    void setTitleHeight(int iheight);
    void setContentHeight(int iheight);
    void setShowContent(bool);

    int getTitleHeight();
    int getContentHeight();
    void resizeEvent(QResizeEvent *event);
public slots:
    void slot_show();

private:
    void movebtn();
    void changeHeight();

    int m_titleheight;
    int m_contentheght;
    bool m_showcontent;
};

/////////////////////////////////////////////////////////////////////////
#include <QScrollArea>
#include <QVBoxLayout>

class QDrawer : public QbaseWidget
{
    Q_OBJECT

public:
    QDrawer(QWidget *parent);
    ~QDrawer();
    
    void addLayerDrawer(QString = "");
    void addLayerDrawerContent(QString, QString, int icontent = -1);//icontent 从零开始
    void addLayerDrawerContent(int, QString, int icontent = -1);//icontent 从零开始

    void setTitleHeight(int iheight, int layerNum = -1);
    void setContentHeight(int iheight, int layerNum = -1);
    void setLayerDrawerbackgroud(int layerNum,QString);

    int getLayerDrawerNum(QString layertitle);
    int getTitleHeight(int layerNum);
    int getContentHeight(int layerNum);
    
    void resizeEvent(QResizeEvent *event);
private:
    void moveLayerDrawer();
    std::vector<QLayerDrawer*> m_layerDarwer;
    QScrollArea *m_scrollArea;
    QbaseWidget *m_scrollAreaWidget;
    QbaseWidget *m_widgetDrawer;
    QVBoxLayout *m_verticalLayout;
    QSpacerItem *m_verticalSpacer;
};
