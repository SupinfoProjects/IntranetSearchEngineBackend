#include "Connection.h"

Connection::Connection(boost::asio::io_service& io_service)
	: socket_(io_service)
{
}


void Connection::handle_write(const boost::system::error_code& error, size_t bytes)
{
}
