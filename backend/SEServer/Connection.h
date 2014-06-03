#pragma once
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

using boost::asio::ip::tcp;

class Connection
	: public boost::enable_shared_from_this<Connection>
{
public:
	typedef boost::shared_ptr<Connection> pointer;

	static pointer create(boost::asio::io_service& io_service)
	{
		return pointer(new Connection(io_service));
	}

	tcp::socket& socket()
	{
		return socket_;
	}

	void start()
	{
		
	}

private:
	Connection(boost::asio::io_service& io_service);
		

	void handle_write(const boost::system::error_code& /*error*/,
		size_t /*bytes_transferred*/);
	

	tcp::socket socket_;
	std::string message_;
};
