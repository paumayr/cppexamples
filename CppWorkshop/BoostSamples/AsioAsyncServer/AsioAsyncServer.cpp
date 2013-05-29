// AsioAsyncServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <memory>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

class tcp_connection : public std::enable_shared_from_this<tcp_connection>
{
public:

	tcp_connection(boost::asio::io_service &io_service)
		: _socket(io_service), msg("Hello from Server")
	{
	}

	boost::asio::ip::tcp::socket& socket()
	{
		return _socket;
	}

	void send_string()
	{
		using namespace boost::asio;
		auto shared_this = shared_from_this();
		async_write(_socket, buffer(msg), [shared_this](const boost::system::error_code &ec, size_t transferred)
		{
			std::cout << "transferred " << shared_this->msg << std::endl;
			shared_this->_socket.close();
		});
	}
private:
	boost::asio::ip::tcp::socket _socket;
	std::string msg;
};

class my_server
{
	boost::asio::ip::tcp::acceptor _acceptor;
public:
	my_server(boost::asio::io_service &ioservice)
		: _acceptor(ioservice, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 2500))
	{
		start_accept();
	}

	void start_accept()
	{
		using namespace std;
		using namespace boost::asio::ip;

		auto connection = make_shared<tcp_connection>(_acceptor.get_io_service());
		_acceptor.async_accept(connection->socket(), [connection, this](const boost::system::error_code &ec)
		{
			if (!ec)
			{
				connection->send_string();
			}

			this->start_accept();
		});
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	using namespace boost::asio;

	try
	{
		io_service ioservice;

		my_server server(ioservice);

		ioservice.run();
	} catch(exception &ex)
	{
		cerr << ex.what() << endl;
	}
	
	return 0;
}

