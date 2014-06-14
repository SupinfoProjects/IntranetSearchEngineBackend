#include <stdio.h>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/lexical_cast.hpp>

using boost::asio::ip::tcp;

int main(int argc, char** argv)
{
	/*if (argc == 0)
		return 1;*/
	try
	{
		boost::asio::io_service io_service;
		tcp::resolver resolver(io_service);
		tcp::resolver::query query("localhost", boost::lexical_cast<std::string>(13));
		tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
		tcp::socket socket(io_service);
		boost::asio::connect(socket, endpoint_iterator);
		std::cout << "Connected to server, sending stuff" << std::endl;
		socket.send(boost::asio::buffer("keyword"));
		for (;;)
		{
			boost::array<char, 128> buf;
			boost::system::error_code error;

			size_t len = socket.read_some(boost::asio::buffer(buf), error);
			if (error == boost::asio::error::eof)
				break; // Connection closed cleanly by peer.
			else if (error)
				throw boost::system::system_error(error); // Some other error.

			std::cout.write(buf.data(), len);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cin.get();
	return 0;
}