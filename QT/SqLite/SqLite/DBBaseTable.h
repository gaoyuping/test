#ifndef BDBASE_H
#define BDBASE_H

#include <QSqlDatabase>

class DBBaseTable
{
public:
    explicit DBBaseTable(QSqlDatabase* dbConnect);
    virtual ~DBBaseTable();
    virtual bool createTable(){ return false; };
    virtual bool dropTable(){ return false; };

    virtual bool tableIsExit(const QString &strTableName);
    virtual bool FieldValueIsExist(const QString &strTableName, const QString &strFieldName, const QString &strFiedValue);


    bool beginTransaction();
    bool commitTransaction();

    
protected:
    void SetDBConnect(QSqlDatabase* dbConnect);
    QSqlDatabase *m_db;
    bool m_tableExist;

};

#endif//BDBASE_H

