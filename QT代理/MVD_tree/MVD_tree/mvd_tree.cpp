#include "mvd_tree.h"
#include <qmytreedelegate.h>
#include <qmytreeitemmodel.h>
#include <qmytreeview.h>
#include <QPushButton>

#include <QAction>
#include "QMyTreeItem.h"

MVD_tree::MVD_tree(QWidget *parent)
    : QMainWindow(parent)
{
    
    ui.setupUi(this);
    QMyTreeView * m_listView = new QMyTreeView(this);
    QMyTreeItem * rootitem = new QMyTreeItem("title");
    QMyTreeItem * tmp = new QMyTreeItem("America", rootitem, new QPushButton("ssss", m_listView));
    rootitem->appendChild(tmp);
    tmp->appendChild(new QMyTreeItem("111", tmp));
    tmp->appendChild(new QMyTreeItem("222", tmp));
    {
        QMyTreeItem * tmp = new QMyTreeItem("America-1", rootitem, new QPushButton("ssss-1", m_listView));
        rootitem->appendChild(tmp);
        tmp->appendChild(new QMyTreeItem("111-1", tmp));
        tmp->appendChild(new QMyTreeItem("222-1", tmp));
    }

    QMyTreeItemModel* model = new QMyTreeItemModel(rootitem, this);
    QMyTreeDelegate* delegate = new QMyTreeDelegate(this);
    m_listView->resize(200, 200);
    m_listView->setModel(model);
    m_listView->setItemDelegate(delegate);
    m_listView->setHeaderHidden(true);
    //m_listView->setIndentation(0);
    m_listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    connect(m_listView, SIGNAL(doubleClicked(const QModelIndex &)), this,  SLOT(slot_doubleClicked(const QModelIndex &)));
    QAbstractItemDelegate*  tmp11 = m_listView->itemDelegate();

}

MVD_tree::~MVD_tree()
{

}

void MVD_tree::slot_doubleClicked(const QModelIndex &index)
{
    if (index.isValid())
    {
        QMyTreeItem * tmp = static_cast<QMyTreeItem*>(index.internalPointer());
        tmp->data();
    }
}
