#ifndef QMYTREEVIEW_H
#define QMYTREEVIEW_H

#include <QTreeView>

class QMyTreeView : public QTreeView
{
    Q_OBJECT

public:
    QMyTreeView(QWidget *parent);
    ~QMyTreeView();

protected:
    void mouseReleaseEvent(QMouseEvent *event);
private:
    
};

#endif // QMYTREEVIEW_H
