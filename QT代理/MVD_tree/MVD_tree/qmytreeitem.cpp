#include "qmytreeitem.h"

QMyTreeItem::QMyTreeItem(const QVariant data, QMyTreeItem * parenItem)
:_data(data), _parentItem(parenItem)
{

}

QMyTreeItem::~QMyTreeItem()
{
    qDeleteAll(_childItems);
}


void QMyTreeItem::appendChild(QMyTreeItem* item)
{
    _childItems.append(item);
}

void QMyTreeItem::removeChild(int irow)
{
    _childItems.removeAt(irow);//ɾ�����ͷ�ָ��ô��
}

void QMyTreeItem::updateChild(int irow, QMyTreeItem *item)
{
    _childItems[irow] = item;
}

int QMyTreeItem::row()
{
    if (_parentItem)
    {
        return _parentItem->_childItems.indexOf(const_cast<QMyTreeItem*>(this));
    }
    return 0;
}

int QMyTreeItem::childCount()
{
    return _childItems.count();
}


QMyTreeItem *QMyTreeItem::child(int row)
{
    return _childItems.value(row);
}

QMyTreeItem *QMyTreeItem::parentItem() const
{
    return _parentItem;
}

QVariant QMyTreeItem::data() const
{
    return _data;
}