#ifndef QMYTREEDELEGATE_H
#define QMYTREEDELEGATE_H

#include <QStyledItemDelegate>

class QMyTreeDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    QMyTreeDelegate(QObject *parent);
    ~QMyTreeDelegate();

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
private:
    
};

#endif // QMYTREEDELEGATE_H
