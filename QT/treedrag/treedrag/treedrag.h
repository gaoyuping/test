#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_treedrag.h"

class treedrag : public QMainWindow
{
    Q_OBJECT

public:
    treedrag(QWidget *parent = Q_NULLPTR);

private:
    Ui::treedragClass ui;
};
