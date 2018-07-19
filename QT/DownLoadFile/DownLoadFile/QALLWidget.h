#ifndef QALLWIDGET_H
#define QALLWIDGET_H

#include <QWidget>
#include <QObject>
#include <QEvent>
#include <QDebug>

class QALLWidgetNotify : public QObject
{
    Q_OBJECT

    class CGarbo // ����Ψһ��������������������ɾ��CSingleton��ʵ�� 
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
