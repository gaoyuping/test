#ifndef QMYLISTDELEGATE_H
#define QMYLISTDELEGATE_H

#include <QStyledItemDelegate>

class QMyListDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    QMyListDelegate(QObject *parent);
    ~QMyListDelegate();

private:

public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // QMYLISTDELEGATE_H
