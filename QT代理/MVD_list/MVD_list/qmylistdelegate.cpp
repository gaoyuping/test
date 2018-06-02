#include "qmylistdelegate.h"
#include <QPainter>

QMyListDelegate::QMyListDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QMyListDelegate::~QMyListDelegate()
{

}

void QMyListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    int margin = 25;
    QRect rect = option.rect;
    rect.setWidth(rect.width() - margin);
    rect.setX(rect.x() + margin);

    QFont normalFont("Microsoft Yahei", 9);
    painter->setFont(normalFont);

    painter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, index.data(Qt::DisplayRole).toString());

}