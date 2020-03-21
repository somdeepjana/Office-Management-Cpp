#pragma once
#include <SQLAPI.h>
#include <iostream>

class Cl_ui
{
public:
	void start_margin(const char&&, const char&&, const char&&);
	void heading(const std::string&&);
	void seperation_line();
	void table_line(const char&&);
	void ask_for_input(const std::string&& text_to_ask, const char&& end_style, const char&& printing_mode);

	void main_menu();

	void view_employ_list(SACommand*);

	

	

	void employee_profile(SACommand* profile_data);

	
};

