#include "mvd_list.h"
#include "qmylistmodel.h"
#include "qmylistdelegate.h"
#include "qmylistview.h"

MVD_list::MVD_list(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QMyListView * m_listView = new QMyListView(this);
    QMyListModel* model = new QMyListModel(this);
    QMyListDelegate* delegate = new QMyListDelegate(this);
    m_listView->resize(100, 200);
    m_listView->setModel(model);
    m_listView->setItemDelegate(delegate);
    connect(m_listView, SIGNAL(clicked(const QModelIndex &)), model, SLOT(Collapse(const QModelIndex&)));

    std::vector<QMyListModel::TreeNode> m_nodeList;
    
    for (int i = 0; i < 3; ++i)
    {
        QMyListModel::TreeNode tmp;
        tmp.count = 3;
        tmp.level = 0;
        tmp.label = QString("ssss-").append(QString::number(i));
        for (int j = 0; j < 3; ++j)
        {
            QMyListModel::TreeNode *tmp1 = new QMyListModel::TreeNode();;
            tmp1->count = 0;
            tmp1->level = 1;
            tmp1->label = QString("ch-").append(QString::number(j));
            tmp.children.push_back(tmp1);
        }
        m_nodeList.push_back(tmp);
    }
    model->AddData(m_nodeList);
}

MVD_list::~MVD_list()
{

}
