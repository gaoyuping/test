#include "sqlite.h"


#include "SQLTabletest.h"

SqLite::SqLite(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_dbmanger = new SQLDb("atest.db");
    m_dbmanger->openTable("ok");
}

SqLite::~SqLite()
{
    delete m_dbmanger;
    m_dbmanger = nullptr;
}
