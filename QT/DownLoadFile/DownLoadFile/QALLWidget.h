#ifndef QALLWIDGET_H
#define QALLWIDGET_H

#include <QWidget>
#include <QObject>
#include <QEvent>
#include <QDebug>

class QALLWidgetNotify : public QObject
{
    Q_OBJECT

    class CGarbo // 它的唯一工作就是在析构函数中删除CSingleton的实例 
    {
    public:
        ~CGarbo()
        {
            qInfo() << "ssssssssssssss";
            if (QALLWidgetNotify::m_AllWidgetNotify)
                delete QALLWidgetNotify::m_AllWidgetNotify;
        }
    };
    static CGarbo Garbo;
    public:
    static QALLWidgetNotify *m_AllWidgetNotify;
public:
    QALLWidgetNotify(QWidget *parent = nullptr);
    ~QALLWidgetNotify();
    static QALLWidgetNotify *GetInstance();

signals:
    void signalhide(QObject *, QEvent *);
};


class QALLWidget : public QWidget
{
    Q_OBJECT

public:
    QALLWidget(QWidget *parent = nullptr);
    ~QALLWidget();
    void paintEvent(QPaintEvent * event);
    static QALLWidget *GetInstance();
private:
    
};

#endif // QALLWIDGET_H
