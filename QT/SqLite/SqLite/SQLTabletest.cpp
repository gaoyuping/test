#include "SQLTabletest.h"


SQLTabletest::SQLTabletest(QSqlDatabase* dbConnect)
    :DBBaseTable(dbConnect)
{
    if (!tableIsExit("OrgStaffInfo"))
    {
        createTable();
    }
}


SQLTabletest::~SQLTabletest()
{
}

#include <QSqlQuery>
bool SQLTabletest::createTable()
{

        QSqlQuery query(*m_db);
bool ret = query.exec("Create TABLE MAIN.[OrgStaffInfo]([infoId] TEXT PRIMARY KEY UNIQUE NOT NULL,[avatar] TEXT, [email] TEXT,[fromWhere] INTEGER,[name] TEXT,[namePy] TEXT,[orgId] TEXT, [staffId] TEXT,[tcard] TEXT, [tel] TEXT,[tmail] TEXT,[updateTime] TEXT\
                                                         ,[createTime] TEXT,[cardNum] TEXT,[cardType] TEXT,[deptId] TEXT,[employeeLevel] TEXT,[userId] TEXT,[isex] TEXT, [istate] TEXT)");
return ret;
}
bool SQLTabletest::dropTable()
{
    return false;
}
