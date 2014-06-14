#include <iostream>
#include <string>
#include "Listener.h"
#include "Sender.h"
#include "Database.h"

int main()
{
	boost::asio::io_service io_service;
	Listener listener = Listener(io_service);
	Database database = Database("yowtf");
	if (database.HasError())
	{
		std::cout << "Encountered MySQL Error: " << database.LastError() << std::endl;
		std::cout << "Couldn't connect to MySQL Database" << std::endl;
	}
	else
	{
		bool e = database.Query("INSERT INTO test");
		if (e)
		{
			std::cout << "Inserted new test row" << std::endl;
		}
		else
		{
			std::cout << "Encountered MySQL Error: " << database.LastError() << std::endl;
		}
	}
	
	io_service.run();
}