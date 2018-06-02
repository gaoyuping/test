#ifndef MVD_LIST_H
#define MVD_LIST_H

#include <QtWidgets/QMainWindow>
#include "ui_mvd_list.h"

class MVD_list : public QMainWindow
{
    Q_OBJECT

public:
    MVD_list(QWidget *parent = 0);
    ~MVD_list();

private:
    Ui::MVD_listClass ui;
};

#endif // MVD_LIST_H
