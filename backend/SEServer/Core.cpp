#include <iostream>
#include <string>
#include "Listener.h"
#include "Sender.h"
#include "Database.h"

int main()
{
	boost::asio::io_service io_service;
	Listener listener = Listener(io_service);
	Database database = Database("searchengine", "192.168.1.126", "root", "", 3306);
	if (database.HasError())
	{
		std::cout << "Couldn't connect to MySQL Database: " << database.LastError() << std::endl;
	}
	else
	{
		bool e = database.Query("INSERT INTO DonneesKeywords VALUES(44)");
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
