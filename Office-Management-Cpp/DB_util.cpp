#include "DB_util.h"

#include <stdlib.h>

#include <SQLAPI.h>

#define SERVER_LOCATON "localhost"
#define USER_ID "root"
#define USER_PASSWORD "toor"
#define OPERATONAL_DB "officemanagement"



//DB_util constructure
DB_util::DB_util(const std::string server_location, const std::string user_id, const std::string user_password, const std::string db_name)
{
    this->server_location= server_location;
    this->db_name = db_name;
    this->user_id = user_id;
    this->user_password = user_password;

	this->mysql_connection = new SAConnection;

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

//opening the dbms  connection
void DB_util::open_portal() {
    std::string connection_string = this->server_location + "@" + this->db_name;

    if (this->mysql_connection->isAlive()) {
        this->mysql_connection->Disconnect();
    }
    this->mysql_connection->Connect(connection_string.c_str(), this->user_id.c_str(), this->user_password.c_str(), SA_MySQL_Client);
}

void DB_util::default_address() {
    this->server_location = SERVER_LOCATON;
    this->db_name = OPERATONAL_DB;
    this->user_id = USER_ID;
    this->user_password = USER_PASSWORD;
}

//DB_util mysql_query implimentation
SACommand* DB_util::mysql_query(const std::string query_string)
{
    try {
        this->mysql_command->setCommandText(query_string.c_str());
        this->mysql_command->Execute();
    }
    catch (SAException & e) {
        std::cout << "Cannot Execute Query";
        system("pause");
    }

	return this->mysql_command;
}

//all setters
void DB_util::set_server_location(const std::string& server_location) {
    this->server_location = server_location;
}
void DB_util::set_db_name(const std::string& db_name) {
    this->db_name = db_name;
}
void DB_util::set_user_id(const std::string& user_id) {
    this->user_id = user_id;
}
void DB_util::set_user_password(const std::string& user_password) {
    this->user_password = user_password;
}