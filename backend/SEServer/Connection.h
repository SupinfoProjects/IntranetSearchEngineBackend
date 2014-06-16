#pragma once
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/array.hpp>

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
		auto self(shared_from_this());
		boost::asio::async_read(socket_,boost::asio::buffer(sizebuf,4),
			[this, self](boost::system::error_code ec, std::size_t len)
			{
				if(!ec)
				{
					std::cout << "read succesfully" << "," << len << std::endl;
					std::cout << "Read: " << sizebuf << std::endl;
					std::size_t size = std::atoi(sizebuf);
					std::cout << size << std::endl;
					char* buf = new char[size];
					sprintf(buf, "%s", "");
					socket_.read_some(boost::asio::buffer(buf, sizeof(char)*(size))); 
					std::cout << buf << std::endl;
					std::string message = "loltest;";
					int length = message.length();
					std::ostringstream data;
					char s[5] = "";
					sprintf(s, "%4d", length);
					data << s << message;
					boost::asio::write(socket_,boost::asio::buffer(data.str()));
				}
				else
				{
					std::cout << ec.message() << std::endl;
					socket_.close();
				}
			});
		//message_ = oss.str();
		/*socket_.async_read(boost::asio::buffer(rbuf),
        		boost::bind(&Connection::handle_read, this,
        		boost::asio::placeholders::error,
        		boost::asio::placeholders::bytes_transferred);*/
	}

private:
	Connection(boost::asio::io_service& io_service);

	void handle_write(const boost::system::error_code& /*error*/,
		std::size_t /*bytes_transferred*/)
	{
	}

	void handle_read(const boost::system::error_code& error, 
		std::size_t bytes_transferred)
	{
		std::cout << "Received " << bytes_transferred << " bytes" << std::endl; 
		//std::cout << message_ << std::endl;
	}

	char sizebuf[4];
	tcp::socket socket_;
	std::string message_;
};
