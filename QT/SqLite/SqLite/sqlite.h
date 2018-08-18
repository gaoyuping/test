#ifndef SQLITE_H
#define SQLITE_H

#include <QtWidgets/QMainWindow>
#include "ui_sqlite.h"
#include "SQLDb.h"
class SqLite : public QMainWindow
{
    Q_OBJECT

public:
    SqLite(QWidget *parent = 0);
    ~SqLite();

private:
    Ui::SqLiteClass ui;
    SQLDb *m_dbmanger;
};

#endif // SQLITE_H
