#include "qmytreedelegate.h"
#include <QPainter>

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
    rect.setWidth(rect.width() - margin);
    rect.setX(rect.x() + margin);

    QFont normalFont("Microsoft Yahei", 9);
    painter->setFont(normalFont);

    painter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, index.data(Qt::DisplayRole).toString());
}
