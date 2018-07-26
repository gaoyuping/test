#include "QALLWidget.h"
#include <QMouseEvent>


QALLWidgetNotify* QALLWidgetNotify::m_AllWidgetNotify = NULL;
QALLWidgetNotify::CGarbo QALLWidgetNotify::Garbo;

QALLWidgetNotify::QALLWidgetNotify(QWidget *parent)
    : QObject(parent)
{

}

QALLWidgetNotify::~QALLWidgetNotify()
{

}


QALLWidgetNotify *QALLWidgetNotify::GetInstance()
{
    static QMutex s_mutexallwidgetnotify;
    if (m_AllWidgetNotify == NULL)
    {
        QMutexLocker locker(&s_mutexallwidgetnotify);
        if (m_AllWidgetNotify == NULL)
            m_AllWidgetNotify = new QALLWidgetNotify(nullptr);
    }
    return m_AllWidgetNotify;
}







QALLWidget::QALLWidget(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background-color:rgb(255, 0, 255);");
    setFocusPolicy(Qt::StrongFocus);
    setWindowFlags(windowFlags() | Qt::Popup);
}

#include <QStyleOption>
#include <QPainter>
void QALLWidget::paintEvent(QPaintEvent * event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

QALLWidget::~QALLWidget()
{

}


QALLWidget *QALLWidget::GetInstance()
{
    static QALLWidget *AllWidget;
    static QMutex s_mutexallwidget;
    if (AllWidget == NULL)
    {
        QMutexLocker locker(&s_mutexallwidget);
        if (AllWidget == NULL)
            AllWidget = new QALLWidget(nullptr);
    }
    return AllWidget;
}

