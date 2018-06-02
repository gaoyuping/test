#ifndef QMYTREEITEM_H
#define QMYTREEITEM_H
#include <QVariant>


class QMyTreeItem
{
public:
    QMyTreeItem(const QVariant data, QMyTreeItem * parenItem = nullptr);
    virtual ~QMyTreeItem();

    void appendChild(QMyTreeItem*);
    void removeChild(int irow);
    void updateChild(int irow, QMyTreeItem *);
    void setTitle(const QVariant data){ _data = data; };
    void setParent(QMyTreeItem *parentItem){ _parentItem = parentItem; };

    int row();
    int childCount();
    QMyTreeItem *child(int row);
    QMyTreeItem *parentItem() const;
    QVariant data() const;


private:
    QList<QMyTreeItem*> _childItems;
    QVariant _data;
    QMyTreeItem *_parentItem;
};

#endif // QMYTREEITEM_H
