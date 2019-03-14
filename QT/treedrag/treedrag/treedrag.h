#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_treedrag.h"

class myQAbstractItemDelegate : public QAbstractItemDelegate
{
    Q_OBJECT
public:
    myQAbstractItemDelegate();
    ~myQAbstractItemDelegate();
public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

class treedrag : public QMainWindow
{
    Q_OBJECT

public:
    treedrag(QWidget *parent = Q_NULLPTR);

private:
    Ui::treedragClass ui;
};
