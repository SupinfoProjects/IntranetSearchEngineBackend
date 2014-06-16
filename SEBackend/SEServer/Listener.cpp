#include "Listener.h"


Listener::Listener(boost::asio::io_service& io_service)
	: acceptor(io_service, tcp::endpoint(tcp::v4(), 13))
{
	StartListen();
}


Listener::~Listener()
{
}

void Listener::StartListen()
{
	Connection::pointer new_connection =
		Connection::create(acceptor.get_io_service());

	acceptor.async_accept(new_connection->socket(),
		boost::bind(&Listener::HandleAccept, this, new_connection,
		boost::asio::placeholders::error));
}

void Listener::HandleAccept(Connection::pointer new_connection,
	const boost::system::error_code& error)
{
	std::cout << "Incoming connection" << std::endl;
	if (!error)
	{
		std::cout << "Starting read" << std::endl;
		new_connection->start();
	}
	else
	{
		std::cout << "An error occured" << std::endl;
		throw boost::system::system_error(error);
	}

	StartListen();
}
