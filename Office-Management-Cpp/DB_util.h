#pragma once

#include <mysql/jdbc.h>

class DB_util
{
	sql::Driver* mysql_driver{ nullptr };
	sql::Connection* mysql_connection{ nullptr };

	sql::Statement* mysql_statement{ nullptr };
	

public:

	sql::ResultSet* mysql_resultset{ nullptr };

	//Inetialiizing Constructure
	DB_util(char* server_location, char* user_id, char* user_password, char* db_name);
	
	//Destructure
	~DB_util();

	//Utility Function
	sql::ResultSet* mysql_query(char* query_string);

};

