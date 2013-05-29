// AsioTimers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <boost/asio/io_service.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <vector>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	using namespace boost::asio;
	using namespace boost::posix_time;
	namespace bs = boost::system;

	io_service service;
	
	vector<shared_ptr<deadline_timer>> timers;

	for(int i = 0; i < 20; i++)
	{
		timers.emplace_back(make_shared<deadline_timer>(service, seconds(i * 5)));
		timers.back()->async_wait([i](const bs::error_code &) { cout << "Hello World, after " << i * 5 << " s" << endl; });
	}

	service.post([](){ std::cout << "Hello World, delayed" << std::endl; });

	std::cout << "Hello World, first" << std::endl;

	service.run();
	return 0;
}

