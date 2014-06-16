#include <stdio.h>
#include <iostream>
#include <sstream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/lexical_cast.hpp>

using boost::asio::ip::tcp;

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Syntaxe: SEClient commande:arg1;arg2;..." << std::endl;
		return 1;
	}
	std::ostringstream oss;
	oss << argv[1];
	std::string line = oss.str();
	oss.clear();
	oss.str("");
	try
	{
		boost::asio::io_service io_service;
		boost::system::error_code err;
		tcp::resolver resolver(io_service);
		tcp::resolver::query query("192.168.1.125", boost::lexical_cast<std::string>(13));
		tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
		tcp::socket socket(io_service);
		boost::asio::connect(socket, endpoint_iterator);
		std::string message = line;
		int size = message.length();
		char csize[5] = "";
		std::sprintf(csize, "%4d", size);
		std::ostringstream os;
		os << csize << message;
		std::string data = os.str();
		//std::cout << data << std::endl;
		boost::asio::write(socket,boost::asio::buffer(data));
		boost::system::error_code error;
		char sbuf[5] = "";
		//std::cout << "Receiving from server..." << std::endl;
		boost::asio::read(socket,boost::asio::buffer(sbuf,4));
		//size_t tsize = std::atoi(sbuf);
		//char* buf = new char[tsize];
		std::vector<char> dbuf(socket.available());
		socket.read_some(boost::asio::buffer(dbuf));
		std::string buf;
		for(auto c : dbuf)
		{
        		buf += c;
		}
		std::cout << buf << std::endl;
		socket.close();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
