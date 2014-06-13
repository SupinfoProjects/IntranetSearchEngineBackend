#include "Database.h"


Database::Database(std::string database, std::string host, std::string user, std::string password, int port)
{
	try
	{
		_driver = sql::mysql::get_mysql_driver_instance();
		_connection = _driver->connect(host, user, password);
		_lasterror = "";
		_error = false;
	}
	catch (sql::SQLException &e)
	{
		_error = true;
		_lasterror = e.what() + '(' + e.getErrorCode() + ')';
	}

}

sql::ResultSet* Database::Request(std::string Query) // Executes a query and returns a result
{
	try
	{
		_statement = _connection->createStatement();
		bool execute = _statement->execute(Query);
		if (execute)
		{
			_rset = _statement->getResultSet();
			return _rset;
		}
		else
		{
			return nullptr;
		}
	}
	catch (sql::SQLException &e)
	{
		_lasterror = e.what() + '(' + e.getErrorCode() + ')';
	}
	return nullptr;
	
}

bool Database::Query(std::string Query) // Executes a query
{	
	try
	{
		_statement = _connection->createStatement();
		bool execute = _statement->executeQuery(Query);
		return execute;
	}
	catch (sql::SQLException &e)
	{
		_lasterror = e.what() + '(' + e.getErrorCode() + ')';
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
		_lasterror = e.what() + '(' + e.getErrorCode() + ')';
	}
	return -1;
}

std::string Database::LastError() // Returns last error encountered
{
	return _lasterror;
}

bool Database::HasError()
{
	return _error;
}


Database::~Database()
{
}
