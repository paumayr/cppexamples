#include "stdafx.h"
#include "CppUnitTest.h"

#include <algorithm>

#include "boost/asio.hpp"
#include "boost/bind.hpp"
#include "boost/array.hpp"

#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace boost::asio;
using namespace boost::asio::ip;

namespace Demo_Boost
{
	TEST_CLASS(Asio)
	{
	public:
		TEST_METHOD(TestAsioTimer)
		{
			io_service io;
			deadline_timer t1(io, boost::posix_time::seconds(5));
			deadline_timer t2(io, boost::posix_time::seconds(2));

			Logger::WriteMessage("Before Queue Timer!\n");

			t1.async_wait([](const boost::system::error_code&)
			{
				Logger::WriteMessage("timer1!\n");
			});

			t2.async_wait([](const boost::system::error_code&)
			{
				Logger::WriteMessage("timer2!\n");
			});

			// io runs until last timer has run out.
			io.run();
		}

	};
}