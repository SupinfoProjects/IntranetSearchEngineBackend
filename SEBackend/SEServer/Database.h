#pragma once
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <sstream>

class Database
{
public:
	Database(std::string database, std::string host = "tcp://127.0.0.1", std::string user = "root", std::string password = "", int port = 3306);
	~Database();

	// Methods
	sql::ResultSet* Request(std::string Query);
	bool Query(std::string Query);
	std::string LastError();
	int Update(std::string Query);
	bool HasError();
private:
	sql::Connection* _connection;
	sql::Driver* _driver;
	sql::Statement* _statement;
	sql::ResultSet* _rset;
	std::string _lasterror;
	bool _error;
};

