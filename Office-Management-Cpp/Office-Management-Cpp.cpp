#include <iostream>

#include <SQLAPI.h>

#include "DB_util.h"

//Diapla Funcions prototype;
void view_table(SACommand* table_data);


int main()
{
    std::cout << "Office Management System\n";

    DB_util* mysql_portal = new DB_util();

    

    
    view_table(mysql_portal->mysql_query("select * from coupons"));


    delete mysql_portal;
}

void view_table(SACommand* table_data)
{
    int col_count = table_data->FieldCount();

    for (int i = 1; i <= col_count; i++) {
        printf("%20s\t", table_data->Field(i).Name());
    }

    std::cout << std::endl << std::string((col_count+1) * 20, '-')<<std::endl;

    while (table_data->FetchNext())
    {
        for (int i = 1; i <= col_count; i++) {
            printf("%20s\t", table_data->Field(i).asString());
        }
        std::cout<<std::endl;
    }
    table_data = nullptr;
    delete table_data;
}

