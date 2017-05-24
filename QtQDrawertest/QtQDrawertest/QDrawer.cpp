#include "QDrawer.h"












QLayerDrawer::QLayerDrawer(QWidget *parent)
    : QbaseWidget(parent), m_btntitle(this)
{
    m_showcontent = false;
    m_titleheight = 25;
    m_contentheght = 20;
    m_btntitle.setFixedHeight(m_titleheight);
    m_btntitle.move(0, 0);
    m_btntitle.setText("DrawerTitle");
    setFixedHeight(m_titleheight);
    connect(&m_btntitle, SIGNAL(released()), this, SLOT(slot_show()));
}

QLayerDrawer::~QLayerDrawer()
{
    std::vector<QPushButton*>::iterator iter = m_veccontent.begin();
    for (; iter != m_veccontent.end();)
    {
        QPushButton * tmp = *iter;
        iter = m_veccontent.erase(iter);
        delete tmp;
    }
}

void QLayerDrawer::setTitleTxt(QString str)
{
    if (str.isEmpty())
    {
        return;
    }
    m_btntitle.setText(str);
}

QString QLayerDrawer::getTitleTxt()
{
    return m_btntitle.text();
}
void QLayerDrawer::addContent(QString str, int icontent)
{
    QPushButton * tmp = new QPushButton(this);
    tmp->setText(str);
    tmp->setFixedSize(width(), m_contentheght);
    if (0 > icontent || icontent >=m_veccontent.size())
    {
        m_veccontent.push_back(tmp);
    }
    else
    {
        m_veccontent.insert(m_veccontent.begin() + icontent, tmp);
    }
    
    movebtn();
}

void QLayerDrawer::setTitleHeight(int iheight)
{
    m_titleheight = iheight;
    m_btntitle.setFixedHeight(m_titleheight);
    movebtn();
}

void QLayerDrawer::setContentHeight(int iheight)
{
    if (m_contentheght != iheight)
    {
        m_contentheght = iheight;
        movebtn();
    }
}

void QLayerDrawer::setShowContent(bool bshow)
{
//     if (m_showcontent != bshow)
//     {
        m_showcontent = bshow;
        changeHeight();
    //}
}

int QLayerDrawer::getTitleHeight()
{
    return m_titleheight;
}

int QLayerDrawer::getContentHeight()
{
    return m_contentheght;
}

void QLayerDrawer::resizeEvent(QResizeEvent *event)
{
    int iwidth = width();
    m_btntitle.setFixedWidth(iwidth);
    std::vector<QPushButton*>::iterator iter = m_veccontent.begin();
    for (; iter != m_veccontent.end(); iter++)
    {
        (*iter)->setFixedWidth(iwidth);
    }
    __super::resizeEvent(event);
}

void QLayerDrawer::slot_show()
{
    m_showcontent = !m_showcontent;
    changeHeight();
    emit signal_showcontent();
}

void QLayerDrawer::movebtn()
{
    int inum = 0;
    std::vector<QPushButton*>::iterator iter = m_veccontent.begin();
    for (; iter != m_veccontent.end(); iter++)
    {
        (*iter)->setFixedHeight(m_contentheght);
        (*iter)->move(0, m_titleheight + inum*m_contentheght);
        inum++;
    }
    
    changeHeight();
}

void QLayerDrawer::changeHeight()
{
    int inum = m_veccontent.size();
    if (m_showcontent)
    {
        setFixedHeight(m_titleheight + m_contentheght * inum);
    }
    else
    {
        setFixedHeight(m_titleheight);
    }
}
//////////////////////////////////////////////////////////////////////////
QDrawer::QDrawer(QWidget *parent)
    : QbaseWidget(parent)
{

    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setObjectName(QStringLiteral("scrollArea"));
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollAreaWidget = new QbaseWidget();
    m_scrollAreaWidget->setObjectName(QStringLiteral("scrollAreaWidget"));
    m_scrollAreaWidget->setGeometry(QRect(0, 0, 580, 323));
    m_scrollAreaWidget->setStyleSheet("background-color:#FFFFFF00");

    //m_scrollAreaWidget->show();
    m_verticalLayout = new QVBoxLayout(m_scrollAreaWidget);
    m_verticalLayout->setSpacing(6);
    m_verticalLayout->setContentsMargins(0, 0, 0, 0);
    m_verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    m_widgetDrawer = new QbaseWidget(m_scrollAreaWidget);
    m_widgetDrawer->setObjectName(QStringLiteral("widgetDrawer"));
    m_widgetDrawer->setStyleSheet("background-color:#FFFF00FF");
    m_verticalLayout->addWidget(m_widgetDrawer);
//     m_widgetDrawer->raise();
//     m_widgetDrawer->setFixedHeight(100);
    m_verticalSpacer = new QSpacerItem(20, 286, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_verticalLayout->addItem(m_verticalSpacer);
    m_scrollArea->setWidget(m_scrollAreaWidget);

    resize(200, 200);
}

QDrawer::~QDrawer()
{
}

void QDrawer::addLayerDrawer(QString strtitle)
{
    QLayerDrawer * tmp = new QLayerDrawer(m_widgetDrawer);
    tmp->setTitleTxt(strtitle);
    tmp->show();
    m_layerDarwer.push_back(tmp);
    int i = tmp->height();
    moveLayerDrawer();
    connect(tmp, &QLayerDrawer::signal_showcontent, [this, tmp]{
        std::vector<QLayerDrawer*>::iterator iter = m_layerDarwer.begin();
        int iheightall = 0;
        for (;iter != m_layerDarwer.end(); iter++)
        {
            if (*iter != tmp)
            {
                (*iter)->setShowContent(false);
            }
        }
        moveLayerDrawer();
    });
}

void QDrawer::addLayerDrawerContent(QString strtitle, QString strtxt, int icontent)
{
    std::vector<QLayerDrawer*>::iterator iter = m_layerDarwer.begin();
    for (; iter != m_layerDarwer.end(); iter++)
    {
        QString str = (*iter)->getTitleTxt();
        if (0 == str.compare(strtitle))
        {
            (*iter)->addContent(strtxt, icontent);
            break;
        }
    }
}

void QDrawer::addLayerDrawerContent(int icout, QString strtxt, int icontent)
{
    std::vector<QLayerDrawer*>::iterator iter = m_layerDarwer.begin();
    int iheightall = 0;
    iter = iter + icout;
    if (iter != m_layerDarwer.end())
    {
        (*iter)->addContent(strtxt, icontent);
    }
}

void QDrawer::setTitleHeight(int iheight, int layerNum)
{
    std::vector<QLayerDrawer*>::iterator iter = m_layerDarwer.begin();
    if (-1 == layerNum)
    {
        for (; iter != m_layerDarwer.end(); iter++)
        {
            (*iter)->setTitleHeight(iheight);
        }
    }
    else
    {
        for (; iter != m_layerDarwer.end(); iter++)
        {
            if (layerNum == iter - m_layerDarwer.begin())
            {
                (*iter)->setTitleHeight(iheight);
                break;;
            }
        }
    }
    moveLayerDrawer();
}

void QDrawer::setContentHeight(int iheight, int layerNum)
{
    std::vector<QLayerDrawer*>::iterator iter = m_layerDarwer.begin();
    if (-1 == layerNum)
    {
        for (; iter != m_layerDarwer.end(); iter++)
        {
            (*iter)->setContentHeight(iheight);
        }
    }
    else
    {
        for (; iter != m_layerDarwer.end(); iter++)
        {
            if (layerNum == iter - m_layerDarwer.begin())
            {
                (*iter)->setContentHeight(iheight);
                break;;
            }
        }
    }
    moveLayerDrawer();
}

void QDrawer::setLayerDrawerbackgroud(int layerNum, QString strcolor)
{
    std::vector<QLayerDrawer*>::iterator iter = m_layerDarwer.begin();
    int iheightall = 0;
    iter = iter + layerNum;
    if (iter != m_layerDarwer.end())
    {
        (*iter)->setStyleSheet("background-color:"+ strcolor);
    }
}
int QDrawer::getLayerDrawerNum(QString layertitle)
{
    std::vector<QLayerDrawer*>::iterator iter = m_layerDarwer.begin();
    for (; iter != m_layerDarwer.end(); iter++)
    {
        QString str = (*iter)->getTitleTxt();
        if (0 == str.compare(layertitle))
        {
            return iter - m_layerDarwer.begin();
        }
    }
    return -1;
}

int QDrawer::getTitleHeight(int layerNum)
{
    std::vector<QLayerDrawer*>::iterator iter = m_layerDarwer.begin();
    for (; iter != m_layerDarwer.end(); iter++)
    {
        if (layerNum == iter - m_layerDarwer.begin())
        {
            return (*iter)->getTitleHeight();
        }
    }
}

int QDrawer::getContentHeight(int layerNum)
{
    std::vector<QLayerDrawer*>::iterator iter = m_layerDarwer.begin();
    for (; iter != m_layerDarwer.end(); iter++)
    {
        if (layerNum == iter - m_layerDarwer.begin())
        {
            return (*iter)->getContentHeight();
        }
    }
}

#include <QScrollBar>
void QDrawer::resizeEvent(QResizeEvent *event)
{
    int iwidth = width();
    m_scrollArea->move(0, 0);
    m_scrollArea->resize(width(), height());

    std::vector<QLayerDrawer*>::iterator iter = m_layerDarwer.begin();
    if (iter != m_layerDarwer.end())
    {
        for (; iter != m_layerDarwer.end(); iter++)
        {
            (*iter)->setFixedWidth(iwidth);
        }
    }

    __super::resizeEvent(event);
}
void QDrawer::moveLayerDrawer()
{
    std::vector<QLayerDrawer*>::iterator iter = m_layerDarwer.begin();
    int iheightall = 0;
    for (; iter != m_layerDarwer.end(); iter++)
    {
        //iter->height()
        (*iter)->move(0, iheightall);
        iheightall += (*iter)->height();
    }
    m_widgetDrawer->setFixedHeight(iheightall);
}

