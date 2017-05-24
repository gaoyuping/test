#pragma once

#include "QDrawer.h"

#include <QtWidgets/QMainWindow>
#include "ui_QtQDrawertest.h"

class QtQDrawertest : public QMainWindow
{
    Q_OBJECT

public:
    QtQDrawertest(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtQDrawertestClass ui;
    QDrawer *ssss;
};
