#include "qmytreeview.h"

QMyTreeView::QMyTreeView(QWidget *parent)
    : QTreeView(parent)
{

}

QMyTreeView::~QMyTreeView()
{

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
