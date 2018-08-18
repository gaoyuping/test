#include "SQLDb.h"
#include <QSqlDatabase>
#include <QSqlQuery>

#include "SQLTabletest.h"
SQLDb::SQLDb(QString strdbpath)
{
    m_Db = QSqlDatabase::addDatabase("QSQLITE", strdbpath);
    m_Db.setDatabaseName(strdbpath);
    if (m_Db.open())
    {
        QSqlQuery query(m_Db);
        bool ret = query.exec("PRAGMA synchronous = OFF; ");
    }
}


SQLDb::~SQLDb()
{
    for (std::map<QString, DBBaseTable*>::iterator iter = m_mapTable.begin(); iter != m_mapTable.end();)
    {
        DBBaseTable * tmp = iter->second;
        iter = m_mapTable.erase(iter);
        delete tmp;
    }
    if (m_Db.isOpen())
        m_Db.close();
}

bool SQLDb::openTable(QString strTableName)
{
    SQLTabletest * tmp = new SQLTabletest(&m_Db);
    m_mapTable.insert(std::make_pair(strTableName, tmp));
    return true;
}