

#include "DB_util.h"

#include <SQLAPI.h>


//DB_util constructure
DB_util::DB_util(const std::string& server_location, const std::string& user_id, const std::string& user_password, const std::string& db_name)
{
	std::string connection_string = server_location + "@" + db_name;
	this->mysql_connection = new SAConnection;
	this->mysql_connection->Connect(connection_string.c_str(), user_id.c_str(), user_password.c_str(), SA_MySQL_Client);

	this->mysql_command = new SACommand;
	this->mysql_command->setConnection(mysql_connection);
}

//DB_util Destructure
DB_util::~DB_util()
{

	delete this->mysql_command;
}

//DB_util mysql_query implimentation
SACommand* DB_util::mysql_query(const std::string query_string)
{
	this->mysql_command->setCommandText(query_string.c_str());
	this->mysql_command->Execute();
	return this->mysql_command;
}