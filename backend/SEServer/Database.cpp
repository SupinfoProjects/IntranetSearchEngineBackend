#include "Database.h"


Database::Database(std::string database, std::string host, std::string user, std::string password, int port)
{
	try
	{
		_error = false;
		_driver = sql::mysql::get_mysql_driver_instance();
		_lasterror = "";
		std::ostringstream oss;
		oss << "tcp://" << host << ":" << port;
		std::string chain = oss.str();
		_connection = _driver->connect(chain, user, password);
		std::string query = "USE " + database;
		_error = !Query(query);
		return;
	}
	catch (sql::SQLException &e)
	{
		_error =  true;
		std::cout << "Exception occured" << std::endl;
		std::ostringstream oss;
		oss << e.what() << '(' << e.getErrorCode() << ')';
		_lasterror = oss.str();
	}

}

sql::ResultSet* Database::Request(std::string Query) // Executes a query and returns a result
{
	try
	{
		_statement = _connection->createStatement();
		_rset = _statement->executeQuery(Query);
		if (_rset != NULL && _rset != nullptr)
		{
			return _rset;
		}
		else
		{
			std::cout << "zeub" << std::endl;
			return nullptr;
		}
	}
	catch (sql::SQLException &e)
	{
		_error = true;
		std::ostringstream oss;
		oss << '[' << Query << ']' << std::endl << e.what() << '(' << e.getErrorCode() << ')';
		_lasterror = oss.str();
	}
	return nullptr;
	
}

bool Database::Query(std::string Query) // Executes a query
{	
	try
	{
		_statement = _connection->createStatement();
		bool execute = _statement->execute(Query);
		return true;
	}
	catch (sql::SQLException &e)
	{
		_error = true;
		std::ostringstream oss;
		oss << '[' << Query << ']' << std::endl << e.what() << '(' << e.getErrorCode() << ')';
 		_lasterror = oss.str();
	}
	return false;
}

int Database::Update(std::string Query) // Updates database entries and returns affected rows
{	
	try
	{
		_statement = _connection->createStatement();
		int execute = _statement->executeUpdate(Query);
		return execute;
	}
	catch (sql::SQLException &e)
	{
		_error = true;
		std::ostringstream oss;
		oss << '[' << Query << ']' << std::endl << e.what() << '(' << e.getErrorCode() << ')';
                _lasterror = oss.str();
	}
	return -1;
}

std::string Database::LastError() // Returns last error encountered
{
	_error = false;
	return _lasterror;
}

bool Database::HasError()
{
	return _error;
}


Database::~Database()
{
	delete _statement;
	delete _connection;
	delete _rset;
}
