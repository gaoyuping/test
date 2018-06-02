#ifndef QMYTREEITEMMODEL_H
#define QMYTREEITEMMODEL_H

#include <QAbstractItemModel>
#include <qmytreeitem.h>

class QMyTreeItemModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    QMyTreeItemModel(QMyTreeItem * rootItem , QObject *parent);
    ~QMyTreeItemModel();

    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation,
        int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QModelIndex index(int row, int column,
        const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

private:
    QMyTreeItem * _rootItem;
    
};

#endif // QMYTREEITEMMODEL_H
