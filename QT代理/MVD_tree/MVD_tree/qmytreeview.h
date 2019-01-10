#ifndef QMYTREEVIEW_H
#define QMYTREEVIEW_H

#include <QTreeView>
#include <QPushButton>

class QMyTreeView : public QTreeView
{
    Q_OBJECT

public:
    QMyTreeView(QWidget *parent);
    ~QMyTreeView();

    void paintEvent(QPaintEvent *event);
protected:
    void mouseReleaseEvent(QMouseEvent *event);
private:
    
};

#endif // QMYTREEVIEW_H
