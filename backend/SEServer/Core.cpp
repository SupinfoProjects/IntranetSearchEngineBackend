#include <iostream>
#include <string>
#include "Listener.h"
#include "Sender.h"

int main()
{
	boost::asio::io_service io_service;
	Listener listener = Listener(io_service);
	std::cout << "Starting server..." << std::endl;
	io_service.run();
}
