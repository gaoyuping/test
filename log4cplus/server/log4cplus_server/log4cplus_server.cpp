// log4cplus_server.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#if 1

//#include <log4cplus/config.h>
#include <log4cplus/configurator.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/socketappender.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/socket.h>
#include <log4cplus/thread/threads.h>
#include <log4cplus/spi/loggerimpl.h>
#include <log4cplus/spi/loggingevent.h>

#include <iostream>

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;
using namespace log4cplus::thread;


namespace loggingserver {
	class ClientThread : public AbstractThread {
	public:
		ClientThread(Socket clientsock)
			: clientsock(clientsock)
		{
			cout << "Received a client connection!!!!" << endl;
		}

		~ClientThread()
		{
			cout << "Client connection closed." << endl;
		}

		virtual void run();

	private:
		Socket clientsock;
	};

}

int
main(int argc, char** argv)
{
// 	if (argc < 3) {
// 		cout << "Usage: port config_file" << endl;
// 		return 1;
// 	}
// 	//int port = atoi(argv[1]);
// 	tstring configFile = LOG4CPLUS_C_STR_TO_TSTRING(argv[2]);
// 
	PropertyConfigurator config("c:\\gyp\\a.txt");
	config.configure();

	ServerSocket serverSocket(9998);
	while (1) {
		loggingserver::ClientThread *thr =
			new loggingserver::ClientThread(serverSocket.accept());
		thr->start();
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////
// loggingserver::ClientThread implementation
////////////////////////////////////////////////////////////////////////////////


void
loggingserver::ClientThread::run()
{
	while (1) {
		if (!clientsock.isOpen()) {
			return;
		}
		SocketBuffer msgSizeBuffer(sizeof(unsigned int));
		if (!clientsock.read(msgSizeBuffer)) {
			return;
		}

		unsigned int msgSize = msgSizeBuffer.readInt();

		SocketBuffer buffer(msgSize);
		if (!clientsock.read(buffer)) {
			return;
		}

		spi::InternalLoggingEvent event = readFromBuffer(buffer);
	std:;cout << event.getLoggerName();
	cout << "---------";
	cout << event.getLogLevel();
	cout << "---------";
	cout << event.getMessage();
	cout << "---------";

	cout <<std::endl;
		Logger logger = Logger::getInstance(event.getLoggerName());
		logger.callAppenders(event);
	}
}
#else
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#endif

