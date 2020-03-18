

#include "DB_util.h"

#include <mysql/jdbc.h>


//DB_util constructure
DB_util::DB_util(char* server_location, char* user_id, char* user_password, char* db_name)
{
	this->mysql_driver = get_driver_instance();
	this->mysql_connection = mysql_driver->connect(server_location, user_id, user_password);

	this->mysql_connection->setSchema(db_name);
	this->mysql_statement = this->mysql_connection->createStatement();
}

//DB_util Destructure
DB_util::~DB_util()
{
	delete this->mysql_resultset;
	delete this->mysql_statement;
	delete this->mysql_connection;
}

//DB_util mysql_query implimentation
sql::ResultSet* DB_util::mysql_query(char* query_string)
{
	this->mysql_resultset= this->mysql_statement->executeQuery(query_string);
	return this->mysql_resultset;
}