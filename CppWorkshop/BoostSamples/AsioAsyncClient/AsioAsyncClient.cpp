// AsioAsyncClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>

int main(int argc, char* argv[])
{
	using boost::asio::ip::tcp;
	using namespace std;

	try
	{
		boost::asio::io_service io_service;

		for (int i = 0; i < 100; i++)
		{
			using namespace std;
			auto socket = make_shared<tcp::socket>(io_service);

			boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 2500);
			socket->async_connect(endpoint,
				[socket](const boost::system::error_code& ec)
			{
				for (;;)
				{
					boost::array<char, 128> buf;
					boost::system::error_code error;

					size_t len = socket->read_some(boost::asio::buffer(buf), error);
					if (error == boost::asio::error::eof)
					{
						break; // Connection closed cleanly by peer.
					}
					else if (error != 0)
					{
						throw boost::system::system_error(error); // Some other error.
					}

					std::cout.write(buf.data(), len);
				}
			});
		}
	
		io_service.run();
		cin.get();
	}
	catch(std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}
