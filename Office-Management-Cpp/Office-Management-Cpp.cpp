#include <iostream>
#include <string>
#include <conio.h>

#include <SQLAPI.h>

#include "DB_util.h"
#include "Cl_ui.h"

//Diapla Funcions prototype;
void view_table(SACommand* table_data);
int main_menu_controller(Cl_ui* );
void add_employee_controller(Cl_ui* , DB_util* );
std::string view_employee_controller(Cl_ui*, DB_util*);
void delete_employee_controller(Cl_ui*, DB_util*);

int main()
{
    //std::cout << "Office Management System\n";

    Cl_ui* ui_portal = new Cl_ui;
    DB_util* mysql_portal = new DB_util();

    mysql_portal->open_portal();

    //ui_portal->employee_profile(mysql_portal->mysql_query("select * from employee_data where employee_id= 'e001'"));
    //system("pause");
    
    while (true)
    {

        switch (main_menu_controller(ui_portal))
        {
        case 1:

            add_employee_controller(ui_portal, mysql_portal);
            break;
        case 2:

            view_employee_controller(ui_portal, mysql_portal);
            break;
        case 3:
            delete_employee_controller(ui_portal, mysql_portal);

            break;
        default:
            break;
        }
    }


    //ui_portal->main_menu();

    ui_portal->view_employ_list(mysql_portal->mysql_query("select * from employee_data"));

    ui_portal->employee_profile(mysql_portal->mysql_query("select * from employee_data"));

    //view_table(mysql_portal->mysql_query("select * from employee_data"));

    delete ui_portal;
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

int main_menu_controller(Cl_ui* ui_portal) {

    while (true)
    {
        system("CLS");

        ui_portal->main_menu();//------------ printing Main Menu View

        switch (_getch())
        {
        case'1':
            return 1;

            break;
        case'2':
            return 2;

            break;
        case'3':
            return 3;

            break;
        default:

            break;
        }
    }

}

void add_employee_controller(Cl_ui* ui_portal, DB_util* mysql_portal) {

    std::string employee_id, employee_name, employee_mobile, department_id, address;

    system("cls");

    ui_portal->heading("Adding New Emploee");

    //all the inputs
    ui_portal->ask_for_input("Assignn Employee  ID", ':', 'h');
    std::getline(std::cin, employee_id);
    std::cout << std::endl;

    ui_portal->ask_for_input("Employee  Name", ':', 'h');
    std::getline(std::cin, employee_name);
    std::cout << std::endl;

    ui_portal->ask_for_input("Mobile No.", ':', 'h');
    std::getline(std::cin, employee_mobile);
    std::cout << std::endl;

    ui_portal->ask_for_input("Department ID", ':', 'h');
    std::getline(std::cin, department_id);
    std::cout << std::endl;

    ui_portal->ask_for_input("Address", ':', 'h');
    std::getline(std::cin, address);
    std::cout << std::endl;

    ui_portal->seperation_line();
    std::cout << std::endl << std::endl;
    ui_portal->ask_for_input("ENTER for adding Or ESC for Main Menu :", ':', 'f');
    std::cout << std::endl << std::endl;
    ui_portal->seperation_line();
    if (_getch() == '\r') {
        mysql_portal->mysql_query("INSERT INTO employee_data(employee_id, employee_name, mobile_no, department_id, addreess) VALUES ('" + employee_id + "','" + employee_name + "','" + employee_mobile + "','" + department_id + "','" + address + "')");
    }

}

std::string view_employee_controller(Cl_ui* ui_portal, DB_util* mysql_portal) {

    std::string employee_id;
    SACommand* quires{ nullptr };

    while (true)
    {
        system("cls");

        ui_portal->view_employ_list(mysql_portal->mysql_query("select * from employee_data"));

        std::cout << std::endl << std::endl;
        ui_portal->ask_for_input("Enter Emplyoee Id for viewing the profile('b' for return) ", ':', 'f');
        std::getline(std::cin, employee_id);

        std::cout << std::endl << std::endl;
        ui_portal->seperation_line();

        if (employee_id == "b") {
            break;
        }
        
        //---------------- cheeck for correct eemployee_id
        quires = mysql_portal->mysql_query("SELECT employee_data.employee_id AS 'Employee ID', employee_data.employee_name AS 'Employee Name', employee_data.mobile_no AS 'Mobile No.', employee_data.joininng_date AS 'Joining Date', departments.department_name AS 'Department Name', employee_data.addreess AS 'Address' FROM employee_data INNER JOIN departments ON employee_data.department_id = departments.departmrent_id WHERE employee_data.employee_id='" + employee_id + "'");
        quires->FetchFirst();
        SAString get_id = (*quires)[1];
        if (get_id.Compare(employee_id.c_str())) {
            continue;
        }

        system("cls");
        ui_portal->employee_profile(quires);//------------ printing the employeee data
        std::cout << std::endl << std::endl;

        ui_portal->ask_for_input("ENTER to Proceed or ESC to go-back ", ':', 'f');

        std::cout << std::endl << std::endl;
        ui_portal->seperation_line();

        if (_getch() == '\r') {
            break;
        }
    }

    quires = nullptr;
    delete quires;
    return employee_id;
}

void delete_employee_controller(Cl_ui* ui_portal, DB_util* mysql_portal) {

    std::string employee_id = view_employee_controller(ui_portal, mysql_portal);

    if (employee_id != "b") {

        mysql_portal->mysql_query("DELETE FROM employee_data WHERE employee_id= '" + employee_id + "'");
    }
}