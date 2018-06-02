#include "qmylistmodel.h"

QMyListModel::QMyListModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

QMyListModel::~QMyListModel()
{

}


void QMyListModel::refresh()
{
    m_list.clear();

    for (std::vector<TreeNode>::iterator iter = m_treelist.begin(); iter != m_treelist.end(); ++iter)
    {
        Node nodetmp;
        nodetmp.label = (*iter).label;
        nodetmp.data = &(*iter);
        m_list.push_back(nodetmp);
        if ((*iter).collapse == true)
        {
            continue;
        }

        //添加子节点
        for (std::vector<TreeNode*>::iterator iterchilren = iter->children.begin(); iterchilren != iter->children.end(); ++iterchilren)
        {
            Node nodetmp;
            nodetmp.label = (*iterchilren)->label;
            nodetmp.data = *iterchilren;
            m_list.push_back(nodetmp);
        }
     }
}

void QMyListModel::AddData(std::vector<TreeNode> nodetreelist)
{
    m_treelist.assign(nodetreelist.begin(), nodetreelist.end());
    refresh();
    if (0 == m_list.size())
    {
        return;
    }
    beginInsertRows(QModelIndex(), 0, m_list.size());
    endInsertRows();
}

int QMyListModel::rowCount(const QModelIndex &parent /* = QModelIndex */) const
{
    return m_list.size();
}

QVariant QMyListModel::data(const QModelIndex &index, int role /* = Qt::DisplayRole */) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_list.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole)
        return m_list[index.row()].label;
//     else if (role == Qt::UserRole)
//         return (unsigned int)(m_list[index.row()].treeNode);

    return QVariant();
}

void QMyListModel::Collapse(const QModelIndex& index)
{

    TreeNode* node = m_list[index.row()].data;

    if (node->children.size() == 0)
        return;

    node->collapse = !node->collapse;

    refresh();
    beginInsertRows(QModelIndex(), 0, m_list.size());
    endInsertRows();
}