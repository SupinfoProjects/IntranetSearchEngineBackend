#include "Connection.h"

Connection::Connection(boost::asio::io_service& io_service)
	: socket_(io_service)
{
	database = new Database("searchengine", "192.168.1.126", "root", "", 3306);
}


