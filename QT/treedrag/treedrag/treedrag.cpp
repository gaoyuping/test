#include "treedrag.h"
#include <MyTreeWidget.h>
#include <QPainter>

myQAbstractItemDelegate::myQAbstractItemDelegate(){};
myQAbstractItemDelegate::~myQAbstractItemDelegate(){};
void myQAbstractItemDelegate::paint(QPainter *painter,
    const QStyleOptionViewItem &option,
    const QModelIndex &index) const
{
    int margin = 0;

    QFont normalFont("Microsoft Yahei", 12);
    painter->setFont(normalFont);
    QTreeItem * ptr = static_cast<QTreeItem*>(index.internalPointer());
    if (ptr)
    {
        if (ptr->getilevel() > 2)
        {
            margin = 30;
        }
    }
    QRect rect = option.rect;
    rect.setWidth(rect.width() - margin);
    rect.setX(rect.x() + margin);
    painter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, index.data(Qt::DisplayRole).toString());
};

QSize myQAbstractItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(200, 20);
};
#include <QDialog>
treedrag::treedrag(QWidget *parent)
    : QMainWindow(parent)
{

    ui.setupUi(this);
    QDialog dlg(this);

    MyTreeWidget * tmp = new MyTreeWidget(&dlg);
    tmp->setItemDelegate(new myQAbstractItemDelegate());
    tmp->header()->hide();
    QTreeItem *imageItem2 = new QTreeItem(tmp, QStringList(QStringLiteral("图像1")));
    imageItem2->setilevel(1);
    QTreeItem *imageItem2_1 = new QTreeItem(imageItem2, QStringList(QStringLiteral("Band1"))); //子节点1
    QTreeItem *imageItem2_2 = new QTreeItem(imageItem2, QStringList(QStringLiteral("Band2"))); //子节点2
    QTreeItem *imageItem2_3 = new QTreeItem(imageItem2, QStringList(QStringLiteral("Band3"))); //子节点2
    QTreeItem *imageItem2_4 = new QTreeItem(imageItem2, QStringList(QStringLiteral("Band4"))); //子节点2
    QTreeItem *imageItem2_5 = new QTreeItem(imageItem2, QStringList(QStringLiteral("Band5"))); //子节点2
    QTreeItem *imageItem2_4_1 = new QTreeItem(imageItem2_4, QStringList(QStringLiteral("Band4_1")),1); //子节点2
    imageItem2_4->addChild(imageItem2_4_1);
    imageItem2->addChild(imageItem2_1);  //添加子节点
    imageItem2->addChild(imageItem2_2);
    imageItem2->addChild(imageItem2_3);
    imageItem2->addChild(imageItem2_4);
    imageItem2->addChild(imageItem2_5);
    imageItem2_1->setilevel(2);
    imageItem2_2->setilevel(2);
    imageItem2_3->setilevel(2);
    imageItem2_4->setilevel(2);
    imageItem2_5->setilevel(2);
    imageItem2_4_1->setilevel(3);

    tmp->expandAll();
    tmp->move(0, 20);
    tmp->resize(200, 200);

    {
        MyTreeWidget * tmp = new MyTreeWidget(this);
        tmp->header()->hide();
        QTreeItem *imageItem2 = new QTreeItem(tmp, QStringList(QStringLiteral("图像2")));
        tmp->expandAll();
        tmp->move(220, 20);
        tmp->resize(200, 200);
    }

    dlg.resize(800, 800);
    dlg.exec();
}
