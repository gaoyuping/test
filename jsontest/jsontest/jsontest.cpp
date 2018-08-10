// jsontest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "json/json.h"


using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
    std::string json_data = R"({"code":0,"data":{"cardInfos":[{"cardId":9615330429367143,"cardType":1,"avatar":"http://fast.scloud.systoon.com/f/lU99llArXF-i6YpQRbyn9em6EePb+SpcAhSmqkx-IggfF.jpg","title":"asdf ","titlePinyin":"asdf","vcardUrl":"http://fast.scloud.systoon.com/f/rkhFisiZEIGONIAC4S7XNHCOrk7kaq-n4eQrp4iJeqEfF.vcf","createTime":1533042936743,"updateTime":1533042936895,"auditPassedFlag":1,"status":1,"auditStatus":1,"defaultCardFlag":0,"tmail":"Zara@tmail.systoon.com"}],"version":1533042936895}})";
    Json::CharReaderBuilder reader;
    Json::CharReader *creader(reader.newCharReader());
    Json::Value root;
    JSONCPP_STRING errs;
    // reader将Json字符串解析到root，root将包含Json里所有子元素  
    if (!creader->parse(json_data.c_str(), json_data.c_str() + json_data.length(), &root, &errs))
    {
        std::cout << "json parse failed\n";
        return 0;
    }

    cout << "demo read from memory using array---------\n";
    Json::Value jsondata = root["data"];
    if (!jsondata.isNull())
    {
        Json::Value jsoncardInfos = jsondata["cardInfos"];
        if (jsoncardInfos.isArray())
        {
            Json::Value jsarr = jsoncardInfos[0];
            cout << "cardId: " << jsarr["cardId"].asUInt64();
        }
    }

    cout << endl << endl;
    getchar();
    delete creader;
    return 0;
}

