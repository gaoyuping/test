#ifndef SQLTEST_H
#define SQLTEST_H

#include "DBBaseTable.h"

class SQLTabletest : public DBBaseTable
{
public:
    SQLTabletest(QSqlDatabase* dbConnect);
    ~SQLTabletest();

    bool createTable();
    bool dropTable();

};

#endif //SQLTEST_H

