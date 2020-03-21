#pragma once

#include <iostream>
#include <SQLAPI.h>

class DB_util
{
	//sql::Driver* mysql_driver{ nullptr };
	std::string server_location;
	std::string db_name;
	std::string user_id;
	std::string user_password;

	SAConnection* mysql_connection;
	SACommand* mysql_command;

public:


	//Inetialiizing Constructure
	DB_util();
	DB_util(const std::string server_location, const std::string user_id, const std::string user_password, const std::string db_name);

	//Destructure
	~DB_util();

	//Utility Function
	SACommand* mysql_query(const std::string query_string);

	//starting the connection;
	void open_portal();

	//delleting the cop constructor and assignment operator
	DB_util(const DB_util& source) = delete;
	DB_util& operator = (const DB_util& source) = delete;


};

