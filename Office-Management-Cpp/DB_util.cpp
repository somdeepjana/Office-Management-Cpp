#include "DB_util.h"

#include <SQLAPI.h>

#define SERVER_LOCATON "localhost"
#define USER_ID "root"
#define USER_PASSWORD "toor"
#define OPERATONAL_DB "mobilerechargestore"



//DB_util constructure
DB_util::DB_util(const std::string server_location, const std::string user_id, const std::string user_password, const std::string db_name)
{
	std::string connection_string = server_location + "@" + db_name;
	this->mysql_connection = new SAConnection;
	this->mysql_connection->Connect(connection_string.c_str(), user_id.c_str(), user_password.c_str(), SA_MySQL_Client);

	this->mysql_command = new SACommand;
	this->mysql_command->setConnection(mysql_connection);
}

//Void constructure
DB_util::DB_util()
	:DB_util(SERVER_LOCATON, USER_ID, USER_PASSWORD, OPERATONAL_DB){}

//DB_util Destructure
DB_util::~DB_util()
{
	this->mysql_connection->Disconnect();
	delete this->mysql_connection;
}

//DB_util mysql_query implimentation
SACommand* DB_util::mysql_query(const std::string query_string)
{
	this->mysql_command->setCommandText(query_string.c_str());
	this->mysql_command->Execute();
	return this->mysql_command;
}