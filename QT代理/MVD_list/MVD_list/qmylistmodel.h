#ifndef QMYLISTMODEL_H
#define QMYLISTMODEL_H

#include <QAbstractListModel>
#include <vector>


class QMyListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    QMyListModel(QObject *parent);
    ~QMyListModel();
    
    struct TreeNode
    {
        QString label;
        int level;
        bool collapse;
        //bool theLast;
        int count;
        std::vector<TreeNode*> children;
    };
    struct Node
    {
        QString label;
        TreeNode* data;
    };
private:
    std::vector<Node> m_list;
    std::vector<TreeNode> m_treelist;

    void refresh();
public:
    void AddData(std::vector<TreeNode>);
    int rowCount(const QModelIndex &parent /* = QModelIndex */) const;
    QVariant data(const QModelIndex &index, int role /* = Qt::DisplayRole */) const;

public slots:
    void Collapse(const QModelIndex& index);
};

#endif // QMYLISTMODEL_H
