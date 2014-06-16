#pragma once
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/array.hpp>
#include "Database.h"

using boost::asio::ip::tcp;

class Connection
	: public boost::enable_shared_from_this<Connection>
{
public:
	typedef boost::shared_ptr<Connection> pointer;

	static pointer create(boost::asio::io_service& io_service)
	{
		return pointer(new Connection(io_service));
	}

	tcp::socket& socket()
	{
		return socket_;
	}

	void start()
	{
		boost::asio::read(socket_,boost::asio::buffer(sizebuf,4));
		std::cout << "Read: " << sizebuf << std::endl;
		std::size_t size = std::atoi(sizebuf);
		std::vector<char> dbuf(socket_.available());
		boost::asio::read(socket_,boost::asio::buffer(dbuf)); 
		std::string buf;
		for(auto c : dbuf)
		{
			buf += c;
		}
		std::cout << buf << std::endl;
		// Parse command
		std::vector<std::string> args;
		std::string arg;
		std::string command;
		bool bcommand = true;
		for(auto c : buf)
		{
        		if(c != ':' && bcommand)
        		{
        		        command += c;
        		}
        		else if(c == ':' && bcommand)
        		{
        		        bcommand = false;
        		}
        		else if(c != ';' && !bcommand)
        		{
                		arg += c;
        		}
        		else if(c == ';' && !bcommand)
        		{
                		args.push_back(arg);
                		arg = "";
        		}
		}
		if(arg != "")
		{
		        args.push_back(arg);
		}
		
		
		std::cout << "Sending result" << std::endl;
		std::string message;
		if(command == "search")
		{
			std::list<std::string> urls = SearchUrl(args);
			std::cout << "Retrieved" << std::endl;
			if(!urls.empty())
			{
				for(auto url : urls)
				{
					message += url + ";";
				}
			}
		}
		else if(command == "submit")
		{
			socket_.close();
		}
		
		int length = message.length();
		std::ostringstream data;
		char s[5] = "";
		sprintf(s, "%4d", length);
		data << s << message;
		std::cout << "Writing" << std::endl;
		boost::asio::write(socket_,boost::asio::buffer(data.str()));
		std::cout << "Done" << std::endl;
		socket_.close();
	}

private:
	Connection(boost::asio::io_service& io_service);
	
	bool AddURL(std::string back_URL, int back_Note)
	{
		sql::ResultSet* u = database->Request("SELECT Url FROM DonneesUrl WHERE Url='"+ back_URL +"';");
		if (u != nullptr)
		{
			char buf[50];
			sprintf(buf, "%d", back_Note);
			std::string note(buf);
			bool q = database->Query("INSERT INTO DonneesUrl(Url,Note) VALUES ('"+ back_URL + "','"+ note +"');");
			if (q)
			{
				std::cout << "Inserted new url" << std::endl;
			}
			else
			{
				std::cerr << "Encountered MySQL Error: " << database->LastError() << std::endl;
			}
			return true;
		}
		else
		{
			std::cerr << "Url already inserted in database" << std::endl;
			return false;
		}
	}

	void AddKeywords(std::list<std::string> back_Keywords, std::string back_urlID)
	{
		for(auto key : back_Keywords)
		{
			bool k = database->Query("INSERT INTO DonneesKeywords(Keyword,DonneesUrlID) VALUES ('"+ key + "','"+ back_urlID +"');");
			if (k)
			{
				std::cout << "Inserted new Keyword: " << key << std::endl;
			}
			else
			{
				std::cerr << "Encountered MySQL Error: " << database->LastError() << std::endl;
			}
		}
	}

	std::list<std::string> SearchUrl(std::vector<std::string> user_Keywords)//on envoi les keywords entrés par l'utilisateur sur le moteur de recherche
	{
		std::list<std::string> url;
		std::list<int> urlID;
		std::vector<int> addedUrlIds;
		for(auto key : user_Keywords)
		{
			auto k = database->Request("SELECT DonneesUrlID FROM DonneesKeywords WHERE Keyword='"+ key +"';");
			if(k != nullptr && k != NULL)
			{
				while(k->next())
				{
					addedUrlIds.push_back(k->getInt("DonneesUrlID"));
				}
			}
			else
			{
				std::cout << database->LastError() << std::endl;
				std::cout << "No result found for keyword " << key << std::endl;
			}

		}
		for(auto id : addedUrlIds)
		{
			urlID.push_back(id);
		}
		urlID.unique();
		std::cout << "Size" << urlID.size() << std::endl;
		for(auto id : urlID)
		{
			std::ostringstream oss;
			oss << id;
			std::string i = oss.str();
			auto k = database->Request("SELECT Url FROM DonneesUrl WHERE ID='"+ i +"' ORDER BY Note DESC;");
			if(k != NULL && k != nullptr)
			{
				k->next();
				url.push_back(k->getString("Url"));
			}
		}
		return url;
	}

	char sizebuf[4];
	tcp::socket socket_;
	Database* database;
};
