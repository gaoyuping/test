#include "treedrag.h"
#include <MyTreeWidget.h>

treedrag::treedrag(QWidget *parent)
    : QMainWindow(parent)
{

    ui.setupUi(this);
    MyTreeWidget * tmp = new MyTreeWidget(this);
    tmp->header()->hide();
    QTreeWidgetItem *imageItem2 = new QTreeWidgetItem(tmp, QStringList(QStringLiteral("图像1")));
    QTreeWidgetItem *imageItem2_1 = new QTreeWidgetItem(imageItem2, QStringList(QStringLiteral("Band1"))); //子节点1
    QTreeWidgetItem *imageItem2_2 = new QTreeWidgetItem(imageItem2, QStringList(QStringLiteral("Band2"))); //子节点2
    QTreeWidgetItem *imageItem2_3 = new QTreeWidgetItem(imageItem2, QStringList(QStringLiteral("Band3"))); //子节点2
    QTreeWidgetItem *imageItem2_4 = new QTreeWidgetItem(imageItem2, QStringList(QStringLiteral("Band4"))); //子节点2
    QTreeWidgetItem *imageItem2_5 = new QTreeWidgetItem(imageItem2, QStringList(QStringLiteral("Band5"))); //子节点2
    QTreeWidgetItem *imageItem2_4_1 = new QTreeWidgetItem(imageItem2_4, QStringList(QStringLiteral("Band4_1")),1); //子节点2
    imageItem2_4->addChild(imageItem2_4_1);
    imageItem2->addChild(imageItem2_1);  //添加子节点
    imageItem2->addChild(imageItem2_2);
    imageItem2->addChild(imageItem2_3);
    imageItem2->addChild(imageItem2_4);
    imageItem2->addChild(imageItem2_5);
    tmp->expandAll();
    tmp->move(0, 20);
    tmp->resize(200, 200);

    {
        MyTreeWidget * tmp = new MyTreeWidget(this);
        tmp->header()->hide();
        QTreeWidgetItem *imageItem2 = new QTreeWidgetItem(tmp, QStringList(QStringLiteral("图像2")));
        tmp->expandAll();
         tmp->move(220, 20);
         tmp->resize(200, 200);
    }
}
