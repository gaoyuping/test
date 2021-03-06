// prototest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "proto/Cdtppackage.pd.h"
#include "proto/Cdtppackage.pb.h"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    CDTPPackage p;
    p.set_command(1);
    p.set_version(2);
    p.set_algorithm(3);
    p.set_sign("data_sign");
    p.set_dem(4);
    p.set_timestamp(99999999999999);
    p.set_pkgid("data_pkgid");
    p.set_from("data_from");
    p.set_to("data_to");
    p.set_senderpk("data_senderpk");
    p.set_receiverpk("data_receiverpk");
    p.set_data("data_data");
    std::ofstream output("./log1.txt");
    //std::fstream output("./log2", ios::out | ios::trunc | ios::binary); 

    if (!p.SerializeToOstream(&output)) {
        cout << "Failed to write msg." << endl;

    }
    output.close();
    //std::fstream in("./log2", ios::in| ios::binary); 
    std::ifstream in("./log1.txt");
    CDTPPackage p1;
    p1.ParseFromIstream(&in);
    in.close();
    cout << "command =" <<p1.command() << endl;
    cout << "version =" << p1.version() << endl;
    cout << "algorithm =" << p1.algorithm() << endl;
    cout << "sign =" << p1.sign() << endl;
    cout << "dem =" << p1.dem() << endl;
    cout << "timestamp =" << p1.timestamp() << endl;
    cout << "pkgid =" << p1.pkgid() << endl;
    cout << "from =" << p1.from() << endl;
    cout << "to =" << p1.to() << endl;
    cout << "senderpk =" << p1.senderpk() << endl;
    cout << "receiverpk =" << p1.receiverpk() << endl;
    cout << "data =" << p1.data() << endl;

    system("pause");
    return 0;
}

