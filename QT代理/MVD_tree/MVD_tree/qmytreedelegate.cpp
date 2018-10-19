#include "qmytreedelegate.h"
#include <QPainter>
#include "QMyTreeItem.h"
QMyTreeDelegate::QMyTreeDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QMyTreeDelegate::~QMyTreeDelegate()
{

}

void QMyTreeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int margin = 0;
    QRect rect = option.rect;
    QString strtxt = index.data(Qt::DisplayRole).toString();
    QFontMetrics fm = painter->fontMetrics();
    rect.setWidth(fm.width(strtxt) + 10);
    rect.setX(rect.x() + margin);

    QFont normalFont("Microsoft Yahei", 9);
    painter->setFont(normalFont);

    painter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, strtxt);
    QMyTreeItem * tmp = static_cast<QMyTreeItem*>(index.internalPointer());
    if (tmp && tmp->getbtn())
    {
        tmp->getbtn()->move(rect.topRight());
    }
}
