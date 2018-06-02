#ifndef MVD_TREE_H
#define MVD_TREE_H

#include <QtWidgets/QMainWindow>
#include "ui_mvd_tree.h"

class MVD_tree : public QMainWindow
{
    Q_OBJECT

public:
    MVD_tree(QWidget *parent = 0);
    ~MVD_tree();

private:
    Ui::MVD_treeClass ui;
};

#endif // MVD_TREE_H
