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
    QMyTreeItem * tmp = new QMyTreeItem("America", rootitem, new QPushButton("America", m_listView));
    rootitem->appendChild(tmp);
    tmp->appendChild(new QMyTreeItem("1_1", tmp));
    tmp->appendChild(new QMyTreeItem("1_2", tmp));
    tmp->appendChild(new QMyTreeItem("1_3", tmp));
    tmp->appendChild(new QMyTreeItem("1_4", tmp));
    tmp->appendChild(new QMyTreeItem("1_5", tmp));
    tmp->appendChild(new QMyTreeItem("1_6", tmp));
    tmp->appendChild(new QMyTreeItem("1_7", tmp));
    tmp->appendChild(new QMyTreeItem("1_8", tmp));
    tmp->appendChild(new QMyTreeItem("1_9", tmp));
    tmp->appendChild(new QMyTreeItem("1_10", tmp));
    tmp->appendChild(new QMyTreeItem("1_11", tmp));
    {
        QMyTreeItem * tmp = new QMyTreeItem("ssss-1", rootitem, new QPushButton("ssss-1", m_listView));
        rootitem->appendChild(tmp);
        tmp->appendChild(new QMyTreeItem("111-1", tmp));
        tmp->appendChild(new QMyTreeItem("111-2", tmp));
        tmp->appendChild(new QMyTreeItem("111-3", tmp));
        tmp->appendChild(new QMyTreeItem("111-4", tmp));
        tmp->appendChild(new QMyTreeItem("111-5", tmp));
        tmp->appendChild(new QMyTreeItem("111-6", tmp));
        tmp->appendChild(new QMyTreeItem("111-7", tmp));
        tmp->appendChild(new QMyTreeItem("111-8", tmp));
        tmp->appendChild(new QMyTreeItem("111-9", tmp));
        tmp->appendChild(new QMyTreeItem("111-10", tmp));
        tmp->appendChild(new QMyTreeItem("111-11", tmp));
        tmp->appendChild(new QMyTreeItem("111-12", tmp));
        tmp->appendChild(new QMyTreeItem("111-13", tmp));
        tmp->appendChild(new QMyTreeItem("111-14", tmp));
        tmp->appendChild(new QMyTreeItem("111-15", tmp));
    }
        {
            QMyTreeItem * tmp = new QMyTreeItem("hhhhhh-1", rootitem, new QPushButton("hhhhh-1", m_listView));
            rootitem->appendChild(tmp);
            tmp->appendChild(new QMyTreeItem("hhhhhh-1", tmp));
            tmp->appendChild(new QMyTreeItem("hhhhhh-2", tmp));
            tmp->appendChild(new QMyTreeItem("hhhhhh-3", tmp));
            tmp->appendChild(new QMyTreeItem("hhhhhh-4", tmp));
            tmp->appendChild(new QMyTreeItem("hhhhhh-5", tmp));
            tmp->appendChild(new QMyTreeItem("hhhhhh-6", tmp));
            tmp->appendChild(new QMyTreeItem("hhhhhh-7", tmp));
            tmp->appendChild(new QMyTreeItem("hhhhhh-8", tmp));
            tmp->appendChild(new QMyTreeItem("hhhhhh-9", tmp));
            tmp->appendChild(new QMyTreeItem("hhhhhh-10", tmp));
            tmp->appendChild(new QMyTreeItem("hhhhhh-11", tmp));
            tmp->appendChild(new QMyTreeItem("hhhhhh-12", tmp));
            tmp->appendChild(new QMyTreeItem("hhhhhh-13", tmp));
            tmp->appendChild(new QMyTreeItem("hhhhhh-14", tmp));
            tmp->appendChild(new QMyTreeItem("hhhhhh-15", tmp));
        }
    QMyTreeItemModel* model = new QMyTreeItemModel(rootitem, m_listView);
    QMyTreeDelegate* delegate = new QMyTreeDelegate(m_listView);
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
