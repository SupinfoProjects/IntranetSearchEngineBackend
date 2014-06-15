#include <iostream>
#include <list>
#include <string>
#include <exception>
#include "Listener.h"
#include "Sender.h"
#include "Database.h"

using namespace std;

void AddKeywords(std::list<std::string> back_Keywords, int back_urlID, Database* database);
bool AddURL(std::string back_URL, int back_Note, Database* database);
void AddKeywords(std::list<std::string> back_Keywords, std::string back_urlID, Database* database);
std::list<std::string> SearchUrl(std::list<std::string> user_Keywords, Database* database);

int main(int argc, char **argv)//Le choice sera le paramètre envoyé au programme pour savoir si on insère une url ou si on choisis de rechercher une url
{
	try
	{
		bool choice;
		if (argc > 1)
		{
			choice = argv[1] == "true" ? true : false;
		}
		std::list<std::string> keywords;//normalement le main recois la liste des keywords, l'url et la note de l'url donc le param1 = choix, param2 = url, param3 = note, param4 = liste des keywords


		std::list<std::string> user_keywords;
		user_keywords.push_back("test");
		int note;
		std::string urlString, urlID;

		urlString = "toto";
		boost::asio::io_service io_service;
		Listener listener = Listener(io_service);
		Database database = Database("searchengine", "192.168.1.126", "root", "", 3306);

		if (database.HasError())
		{
			std::cout << "Encountered MySQL Error during connection: " << database.LastError() << std::endl;
			std::cout << "Couldn't connect to MySQL Database" << std::endl;
		}
		else if(choice)//on check si on veut intégrer une url dans la bdd ou si on en recherche une
		{
			bool check = AddURL(urlString, note, &database);
			if (check)
			{
				sql::ResultSet* u = database.Request("SELECT ID FROM DonneesUrl WHERE Url='"+ urlString +"';");
				if(u != nullptr && u->getFetchSize() > 0)
				{
					u->next();

					urlID = u->getInt("ID");
					AddKeywords(keywords, urlID, &database);
				}
				else
				{
					std::cout << "No match found for that URL (" << urlString << ')' << std::endl;
				}
			}
		}
		else
		{
			std::list<std::string> url = SearchUrl(user_keywords, &database);
			for (auto urlstr : url)
			{
				cout << urlstr << endl;
			}
		}
		io_service.run();
	}
	catch(std::exception &e)
	{
		std::cout << "Exception occured: " << e.what() << std::endl;
	}
}

bool AddURL(std::string back_URL, int back_Note, Database* database)
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
			std::cout << "Encountered MySQL Error: " << database->LastError() << std::endl;
		}
		return true;
	}
	else
	{
		std::cout << "Url already inserted in database" << std::endl;
		return false;
	}
}

void AddKeywords(std::list<string> back_Keywords, std::string back_urlID, Database* database)
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
			std::cout << "Encountered MySQL Error: " << database->LastError() << std::endl;
		}
	}
}

std::list<std::string> SearchUrl(std::list<std::string> user_Keywords, Database* database)//on envoi les keywords entrés par l'utilisateur sur le moteur de recherche
{
	std::list<std::string> url;
	std::list<int> urlID;
	sql::ResultSet* k;
	for(auto key : user_Keywords)
	{
		k = database->Request("SELECT DonneesUrlID FROM DonneesKeywords WHERE Keyword='"+ key +"';");
		if(k != nullptr)
		{
			k->next();
			for(auto urlID_value : urlID)//on check si l'url n'a pas déjà été trouvée et ajoutée a la liste ex: deux mots clés retournent la meme url, on ne retournera pas plusieurs fois la meme url.
			{
				if (k->getInt("ID") != urlID_value)
				{
					urlID.push_back(k->getInt("ID"));
				}
			}
		}
		else
		{
			std::cout << "No result found for keyword " << key << std::endl;
		}

	}
	for(auto id : urlID)
	{
		std::ostringstream oss;
		oss << id;
		std::string i = oss.str();
		k = database->Request("SELECT Url FROM DonneesUrl WHERE ID='"+ i +"' ORDER BY Note DESC;");
		if(k != nullptr)
			url.push_back(k->getString("Url"));
	}
	return url;
}

