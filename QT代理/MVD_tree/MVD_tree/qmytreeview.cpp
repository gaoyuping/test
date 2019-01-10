#include "qmytreeview.h"
#include "qmytreeitemmodel.h"
QMyTreeView::QMyTreeView(QWidget *parent)
    : QTreeView(parent)
{
}

QMyTreeView::~QMyTreeView()
{

}

void QMyTreeView::paintEvent(QPaintEvent *event)
{
    QMyTreeItemModel * ptr = (QMyTreeItemModel*)model();
    ptr->hidebtn();
    __super::paintEvent(event);
}

void QMyTreeView::mouseReleaseEvent(QMouseEvent *event)
{
    __super::mouseReleaseEvent(event);
    if (selectedIndexes().count() > 0)
    {
        QModelIndex tmp = selectedIndexes().at(0);
        setExpanded(tmp, !isExpanded(tmp));
    }
}
