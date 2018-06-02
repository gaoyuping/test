#include "mvd_tree.h"
#include <qmytreedelegate.h>
#include <qmytreeitemmodel.h>
#include <qmytreeview.h>

#include <QAction>
#include "QMyTreeItem.h"

MVD_tree::MVD_tree(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QMyTreeItem * rootitem = new QMyTreeItem("title");
    QMyTreeItem * tmp = new QMyTreeItem("America", rootitem);
    rootitem->appendChild(tmp);
    tmp->appendChild(new QMyTreeItem("111", tmp));
    tmp->appendChild(new QMyTreeItem("222", tmp));
    {
        QMyTreeItem * tmp = new QMyTreeItem("America-1", rootitem);
        rootitem->appendChild(tmp);
        tmp->appendChild(new QMyTreeItem("111-1", tmp));
        tmp->appendChild(new QMyTreeItem("222-1", tmp));
    }
    QMyTreeView * m_listView = new QMyTreeView(this);
    QMyTreeItemModel* model = new QMyTreeItemModel(rootitem, this);
    QMyTreeDelegate* delegate = new QMyTreeDelegate(this);
    m_listView->resize(200, 200);
    m_listView->setModel(model);
    m_listView->setItemDelegate(delegate);
    m_listView->setHeaderHidden(true);
    m_listView->setIndentation(0);
    m_listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    QAbstractItemDelegate*  tmp11 = m_listView->itemDelegate();

}

MVD_tree::~MVD_tree()
{

}
