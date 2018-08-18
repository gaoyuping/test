#ifndef SQLDB_H
#define SQLDB_H

#include <QString>
#include <QSqlDatabase>
#include "DBBaseTable.h"
#include <map>
class SQLDb
{
public:
    SQLDb(QString strdbpath);
    virtual ~SQLDb();

    virtual bool openTable(QString strTableName);
private:
    QSqlDatabase m_Db;
    // table
    std::map<QString, DBBaseTable*> m_mapTable;
};


#endif
