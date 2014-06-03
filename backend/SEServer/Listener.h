#pragma once
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "Connection.h"

using boost::asio::ip::tcp;

class Listener
{
	public:

		Listener(boost::asio::io_service& io_service);
		~Listener();
	private:
		void StartListen();
		void HandleAccept(Connection::pointer new_connection,
			const boost::system::error_code& error);

		boost::asio::io_service* io_service;
		tcp::acceptor acceptor;
};

