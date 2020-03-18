#include <iostream>

#include <SQLAPI.h>

#include "DB_util.h"

void view_table(SACommand* table_data);

int main()
{
    std::string locaton{ "localhost" };
    std::string db_name{ "mobilerechargestore" };

    std::string user_id{ "root" };
    std::string password{ "Conan@1887Doyle" };
    
    std::string query{ "show tables" };

    DB_util* mysql_portal = new DB_util(locaton, user_id, password, db_name);

    std::cout << "Office Management System\n";

    
    view_table(mysql_portal->mysql_query(query));

    delete mysql_portal;
}

void view_table(SACommand* table_data)
{
    int col_count = table_data->FieldCount();
    while (table_data->FetchNext())
    {
        for (int i = 1; i <= col_count; i++) {
            printf("%s\t", table_data->Field(i).asString());
        }
        std::cout<<std::endl;
    }
}