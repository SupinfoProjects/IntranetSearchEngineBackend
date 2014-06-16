#include <stdio.h>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

using namespace boost::asio::ip;

class Handler : public boost::enable_shared_from_this<Handler>
{
public:
	typedef boost::shared_ptr<Handler> pointer;
	static pointer create(boost::asio::io_service& io_service)
	{
		return pointer(new Handler(io_service));
	}

	tcp::socket& socket()
	{
		return _socket;
	}
	
private:
	
	Handler(boost::asio::io_service& io_service)
		:	_socket(io_service)
	{
		tcp::resolver resolver(io_service);
		tcp::resolver::query query("localhost", boost::lexical_cast<std::string>(13));
		boost::asio::connect(_socket, endpoint_iterator);
		_socket.write(boost::asio::buffer("keyword"));
	}
	
	void handle_write(const boost::system::error_code& error, std::size_t bytes)
	{
		std::cout << "I DUNNO MAN" << std::endl;
	}

	void handle_read(const boost::system::error_code& error, std::size_t bytes)
	{
		boost::array<char, bytes> buf
		_socket.read_some(boost::asio::buffer(buf));
		std::cout.write(buf.data(), bytes);
	}
	tcp::socket _socket;
};




		
