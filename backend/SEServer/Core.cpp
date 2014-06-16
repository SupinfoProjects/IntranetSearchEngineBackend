#include <iostream>
#include <list>
#include <string>
#include <exception>
#include "Listener.h"
#include "Sender.h"
#include "Database.h"

using namespace std;

int main(int argc, char **argv)//Le choice sera le paramètre envoyé au programme pour savoir si on insère une url ou si on choisis de rechercher une url
{
	try
	{
		boost::asio::io_service io_service;
		Listener listener = Listener(io_service);
		io_service.run();
	}
	catch(std::exception &e)
	{
		std::cerr << "Exception occurred: " << e.what() << std::endl;
	}
}

