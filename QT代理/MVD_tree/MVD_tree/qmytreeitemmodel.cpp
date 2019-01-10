#include "qmytreeitemmodel.h"
#include <QDebug>

QMyTreeItemModel::QMyTreeItemModel(QMyTreeItem * rootItem, QObject *parent)
: QAbstractItemModel(parent), _rootItem(rootItem)
{
}

QMyTreeItemModel::~QMyTreeItemModel()
{

}
void QMyTreeItemModel::hidebtn()
{
    for (int i = 0; i < _rootItem->childCount(); i++)
    {
        QMyTreeItem *itemptr = (QMyTreeItem *)_rootItem->child(i);
        itemptr->hidebtn();
    }

}
QVariant QMyTreeItemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    QMyTreeItem * item = static_cast<QMyTreeItem*>(index.internalPointer());
    if (Qt::DisplayRole == role)
    {
        //return item->data(index.column());
        return item->data();
    }
    return QVariant();
}

Qt::ItemFlags QMyTreeItemModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;
    return QAbstractItemModel::flags(index);
}

QVariant QMyTreeItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (Qt::Horizontal == orientation && Qt::DisplayRole == role)
    {
        return _rootItem->data();
    }
    return QVariant();
}

QModelIndex QMyTreeItemModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
    {
        return QModelIndex();
    }

    QMyTreeItem *parentItem;
    if (!parent.isValid())
    {
        parentItem = _rootItem;
    }
    else
    {
        parentItem = static_cast<QMyTreeItem*>(parent.internalPointer());
    }

    QMyTreeItem *childItem = parentItem->child(row);
    if (childItem)
    {
        //return QModelIndex();
        return createIndex(row, column, childItem);
    }
    else
    {
        return QModelIndex();
    }
}

QModelIndex QMyTreeItemModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    QMyTreeItem *childItem = static_cast<QMyTreeItem*>(index.internalPointer());
    QMyTreeItem *parentItem = childItem->parentItem();
    qDebug() << childItem->data();;
    if (parentItem == _rootItem)
    {
        return QModelIndex();
    }
    return createIndex(parentItem->row(), 0, parentItem);
}

int QMyTreeItemModel::rowCount(const QModelIndex &parent ) const
{
    QMyTreeItem *parentItem;
    if (parent.column() > 0)
    {
        return 0;
    }

    if (!parent.isValid())
    {
        parentItem = _rootItem;
    }
    else
    {
        parentItem = static_cast<QMyTreeItem*>(parent.internalPointer());
    }
    return parentItem->childCount();
}

int QMyTreeItemModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}
