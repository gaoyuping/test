#ifndef DOWNFILE_INCLUDE_H
#define DOWNFILE_INCLUDE_H
#include <functional>
#include <QJsonObject>
#include <QString>

typedef std::function<void(bool bsuccess, QString strmsg, QJsonObject JsonData)> CallBackFunction;


struct structWaitdata
{
    QString url;
    QString loadpath;
    CallBackFunction callback;
};



#endif ///DOWNFILE_INCLUDE_H