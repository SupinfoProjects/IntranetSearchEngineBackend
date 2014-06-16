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
		boost::system::error_code err;
		tcp::resolver resolver(io_service);
		tcp::resolver::query query("localhost", boost::lexical_cast<std::string>(13));
		tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
		tcp::socket socket(io_service);
		boost::asio::connect(socket, endpoint_iterator);
		std::cout << "Connected to server, sending stuff" << std::endl;
		std::string message = "k";
		int size = message.length();
		char csize[5] = "";
		std::sprintf(csize, "%4d", size);
		std::ostringstream os;
		os << csize << message;
		std::string data = os.str();
		std::cout << data << std::endl;
		boost::asio::write(socket,boost::asio::buffer(data));
		boost::system::error_code error;
		char sbuf[5] = "";
		std::cout << "Receiving from server..." << std::endl;
		boost::asio::async_read(socket,boost::asio::buffer(sbuf,4), 
			[&socket,&sbuf](boost::system::error_code ec, size_t len)
			{
				if(ec)
				{
					std::cout << ec.message() << std::endl;
				}
				std::cout << "Received from server" << std::endl;
				std::cout << "Message size: " << sbuf << std::endl;
				size_t tsize = std::atoi(sbuf);
				char* buf = new char[tsize];
				socket.read_some(boost::asio::buffer(buf, tsize-1));
				std::cout << buf << std::endl;
			});
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cin.get();
	return 0;
}
