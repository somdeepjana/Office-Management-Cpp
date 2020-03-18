#include <iostream>

#include <mysql/jdbc.h>

#include "DB_util.h"

void view_table(sql::ResultSet* table_data);

int main()
{
    char server_location[]{ "tcp://127.0.0.1:3306" };
    char user_id[]{ "root" };
    char password[]{ "Conan@1887Doyle" };
    char db_name[]{ "mobilerechargestore" };
    char query[]{ "SELECT 'Hello World!' AS _message" };

    DB_util* mysql_portal = new DB_util(server_location, user_id, password, db_name);

    std::cout << "Office Management System\n";

    
    view_table(mysql_portal->mysql_query(query));

    delete mysql_portal;
}

void view_table(sql::ResultSet* table_data)
{
    //sql::ResultSetMetaData* metadata = table_data->getMetaData();

    //int col_no = metadata->getColumnCount();
    //std::cout << "Column No= " << col_no << std::endl;

    while (table_data->next())
    {
        //for (int i = 1; i <= col_no; i++) {
        std::string result= table_data->getString("_message");

        std::cout << result;
        //}
        std::cout<<std::endl;
    }
}