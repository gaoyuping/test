// log4cplusreprottosever.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// #include <log4cplus/logger.h>  
// #include <log4cplus/configurator.h>  
// #include <log4cplus/loggingmacros.h>
// #include <iomanip>  
// 
// using namespace log4cplus;
// 
// int _tmain(int argc, _TCHAR* argv[])
// {
// 	BasicConfigurator config;
// 	config.configure();
// 
// 	Logger logger = Logger::getInstance("main");
// 	LOG4CPLUS_WARN(logger, "Hello, World!");
// 	getchar();
// 	return 0;
// } 

#include <log4cplus/logger.h>
#include <log4cplus/socketappender.h>
#include <log4cplus/loglevel.h>
#include <log4cplus/tstring.h>
#include <log4cplus/thread/threads.h>
#include <log4cplus/loggingmacros.h>
#include <iomanip>

using namespace std;
using namespace log4cplus;

int
main(int argc, char **argv)
{
	//log4cplus::helpers::sleep(1);
	tstring serverName = (argc > 1 ? LOG4CPLUS_C_STR_TO_TSTRING(argv[1]) : tstring());
	//    tstring host = LOG4CPLUS_TEXT("192.168.2.10");
	tstring host = LOG4CPLUS_TEXT("127.0.0.1");
	SharedAppenderPtr append_1(new SocketAppender(host, 9998, serverName));
	append_1->setName(LOG4CPLUS_TEXT("First"));
	Logger::getRoot().addAppender(append_1);

	Logger root = Logger::getRoot();
	Logger test = Logger::getInstance(LOG4CPLUS_TEXT("socket.test"));

	LOG4CPLUS_DEBUG(root, "This is"
		<< " a reall"
		<< "y long message." << endl
		<< "Just testing it out" << endl
		<< "What do you think?");
		test.setLogLevel(NOT_SET_LOG_LEVEL);
		LOG4CPLUS_DEBUG(test, "This is a bool: " << true);
		LOG4CPLUS_INFO(test, "This is a char: " << 'x');
		LOG4CPLUS_INFO(test, "This is a short: " << (short)-100);
		LOG4CPLUS_INFO(test, "This is a unsigned short: " << (unsigned short)100);
		//log4cplus::helpers::sleep(0, 500000);
		LOG4CPLUS_INFO(test, "This is a int: " << (int)1000);
		LOG4CPLUS_INFO(test, "This is a unsigned int: " << (unsigned int)1000);
		LOG4CPLUS_INFO(test, "This is a long(hex): " << hex << (long)100000000);
		LOG4CPLUS_INFO(test, "This is a unsigned long: " << (unsigned long)100000000);
		LOG4CPLUS_WARN(test, "This is a float: " << (float)1.2345);
		LOG4CPLUS_ERROR(test, "This is a double: "
			<< setprecision(15)
			<< (double)1.2345234234);
			LOG4CPLUS_FATAL(test, "This is a long double: "
			<< setprecision(15)
			<< (long double)123452342342.342);
			system("pause");
		return 0;
}