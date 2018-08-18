#include "DBBaseTable.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>


DBBaseTable::DBBaseTable(QSqlDatabase* dbConnect)
    :m_tableExist(false)
{
    SetDBConnect(dbConnect);
}


DBBaseTable::~DBBaseTable()
{
}


bool DBBaseTable::tableIsExit(const QString &strTableName)
{
    //如果已经存在，则不判断
    if (m_tableExist)
    {
        return true;
    }
    bool result = false;
    if (strTableName.length() == 0)
    {
        return result;
    }
    if (nullptr == m_db)
    {
        return false;
    }
    QSqlQuery  query(*m_db);
    QString sql = "select count(*) as c from Sqlite_master  where type ='table' and name ='" + strTableName + "' ";
    if (!query.exec(sql))
    {
        return result;
    }
    if (query.next())
    {
        QSqlRecord record = query.record();
        int nCount = record.value(0).toInt();
        if (nCount > 0)
        {
            result = true;
        }
    }

    m_tableExist = result;
    return result;
}

bool DBBaseTable::FieldValueIsExist(const QString &strTableName, const QString &strFieldName, const QString &strFiedValue)
{
    return false;
}

bool DBBaseTable::beginTransaction()
{
    return m_db->transaction();
}

bool DBBaseTable::commitTransaction()
{
    bool bret = m_db->commit();
    if (!bret)
    {
        m_db->rollback();
    }
    return bret;
}

void DBBaseTable::SetDBConnect(QSqlDatabase* dbConnect)
{
    m_db = dbConnect;
}
