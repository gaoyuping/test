#ifndef QMYTREEITEM_H
#define QMYTREEITEM_H
#include <QVariant>
#include <QPushButton>


class QMyTreeItem
{
public:
    QMyTreeItem(const QVariant data, QMyTreeItem * parenItem = nullptr, QPushButton *bntptr = nullptr);
    virtual ~QMyTreeItem();

    void appendChild(QMyTreeItem*);
    void removeChild(int irow);
    void updateChild(int irow, QMyTreeItem *);
    void setTitle(const QVariant data){ _data = data; };
    void setParent(QMyTreeItem *parentItem){ _parentItem = parentItem; };
    QPushButton *getbtn(){ return m_btn; };
    int row();
    int childCount();
    QMyTreeItem *child(int row);
    QMyTreeItem *parentItem() const;
    QVariant data() const;

    void hidebtn();
private:
    QList<QMyTreeItem*> _childItems;
    QVariant _data;
    QMyTreeItem *_parentItem;
    QPushButton *m_btn;
};

#endif // QMYTREEITEM_H
