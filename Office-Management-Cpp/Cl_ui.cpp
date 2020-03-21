#include "Cl_ui.h"

#include <iostream>
#include <iomanip>

#include <SQLAPI.h>

//##########################################   Textual Graphics Mode    ##########################################

#define ESC "\033["
#define END_GMOD "m"
#define NEXT_AT ";"

//Text Attributes
#define TEXT_DSABLE "0"
#define TEXT_BOLD "1"
#define TEXT_UNDERSCORE "4"
#define BLINK_ON "5"

//Foreground Colors
#define F_BLACK "30"
#define F_RED "31"
#define F_GREEN "32"
#define F_YELLOW "33"
#define F_BLUE "34"
#define F_MAGENTRA "35"
#define F_CYAN "36"
#define F_WHITE "37"

//Background Colors
#define B_BLACK "40"
#define B_RED "41"
#define B_GREEN "42"
#define B_YELLOW "43"
#define B_BLUE "44"
#define B_MAGENTRA "45"
#define B_CYAN "46"
#define B_WHITE "47"

//##########################################   Pre-Constructed Graphics Mode    ##########################################
#define BORDER_LINE "\033[1;35m"
#define HEADING_TEXT "\033[1;36m"
#define DISABLE_ALL_FORMAT "\033[0m"


//##########################################   Aligenment Numbers    ##########################################
#define MARGIN_WIDTH 4
#define TEXT_START_GAP 5
#define INTER_COLUMN_GAP 2
#define HEADING_TEXT_TOTAL_AREA 44
#define TOTAL_WRITING_AREA 100


void Cl_ui::main_menu() {

	this->heading("Main Menu ");

	std::cout << std::setw(MARGIN_WIDTH + TEXT_START_GAP + 1) << std::setfill(' ') << "";	//---------- starting text ocatiion

	std::cout << std::left << std::setw(TOTAL_WRITING_AREA / 2) << std::setfill(' ') << "01. Add Employee";
	std::cout << std::right << std::setw(TOTAL_WRITING_AREA / 2) << std::setfill(' ') << "02. View Employee" << std::endl << std::endl;

	std::cout << std::setw(MARGIN_WIDTH + TEXT_START_GAP + 1) << std::setfill(' ') << "";	//---------- starting text ocatiion
	std::cout << std::left << std::setw(TOTAL_WRITING_AREA / 2) << std::setfill(' ') << "03. Delete Employee";

	std::cout << std::endl << std::endl << std::endl;
	this->seperation_line();
	std::cout << std::endl << std::endl;

	std::cout << std::setw(MARGIN_WIDTH + TEXT_START_GAP + 1) << std::setfill(' ') << "";	//---------- starting text ocatiion
	std::cout << "Choose a Option : ";

	std::cout << std::endl << std::endl;
	this->seperation_line();
}

void Cl_ui::view_employ_list(SACommand* table_data) {

	int col_no = table_data->FieldCount();
	int column_width = (TOTAL_WRITING_AREA - (((INTER_COLUMN_GAP * 2) + 1) * (col_no-2))) / (col_no-1);


	this->heading("Viewing All Employee");

	std::cout << std::setw(MARGIN_WIDTH + TEXT_START_GAP + 1) << std::setfill(' ') << "";	//---------- starting text locatiion
	std::cout << std::left;
	std::cout << std::setw(12) << "Employee ID";				std::cout << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << "" << "|" << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << ""; //------------ text intermediate distance with divider
	std::cout << std::setw(20) << "Employee Name";				std::cout << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << "" << "|" << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << ""; //------------ text intermediate distance with divider
	std::cout << std::setw(10) << "Mobie";						std::cout << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << "" << "|" << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << ""; //------------ text intermediate distance with divider
	std::cout << std::setw(20) << "Join Date";					std::cout << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << "" << "|" << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << ""; //------------ text intermediate distance with divider
	std::cout << std::right << std::setw(18) << "Department";
	std::cout << std::endl;

	this->table_line('=');//------ table header line


	while (table_data->FetchNext())
	{

		std::cout << std::right << std::setw(MARGIN_WIDTH + TEXT_START_GAP + 1) << std::setfill(' ') << "";	//---------- starting text locatiion
		std::cout << std::left;
		printf("%-12s", table_data->Field(1).asString());	std::cout << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << "" << "|" << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << ""; //------------ text intermediate distance with divider
		printf("%-20s", table_data->Field(2).asString());	std::cout << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << "" << "|" << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << ""; //------------ text intermediate distance with divider
		printf("%-10s", table_data->Field(3).asString());	std::cout << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << "" << "|" << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << ""; //------------ text intermediate distance with divider
		printf("%-20s", table_data->Field(4).asString());	std::cout << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << "" << "|" << std::setw(INTER_COLUMN_GAP) << std::setfill(' ') << ""; //------------ text intermediate distance with divider
		printf("%18s", table_data->Field(5).asString());
		std::cout << std::endl;

		this->table_line('-'); //-------- table seperation line

	}

	std::cout << std::endl << std::endl;
	
	this->seperation_line();
}

//##########################################   Heading Border    ##########################################
void Cl_ui::heading(const std::string&& heading_text) {
	int blank_padding_length = (HEADING_TEXT_TOTAL_AREA - heading_text.length()) / 2;
	int line_padding_length = (TOTAL_WRITING_AREA - HEADING_TEXT_TOTAL_AREA)/2;

	std::cout << std::endl << std::endl << BORDER_LINE; //---------- starting color
	start_margin(' ', '|', 'f');
	//std::cout << std::setw(MARGIN_WIDTH) << std::setfill(' ')<< "" << "|" << std::setw(TEXT_START_GAP) << std::setfill(' ') << "";	//---------- starting text locatiion

	std::cout << std::setw(line_padding_length) << std::setfill('~')<<"";
	std::cout << std::setw(blank_padding_length) << std::setfill(' ') << ""; //------------ blank pading length(starting)

	std::cout << HEADING_TEXT << heading_text;

	std::cout << BORDER_LINE << std::setw(blank_padding_length) << std::setfill(' ') << ""; //------------ blank pading length(ending)
	std::cout << std::setw(line_padding_length) << std::setfill('~') << "";

	start_margin(' ', '|', 'r');
	//std::cout << std::setw(TEXT_START_GAP) << std::setfill(' ') << "" << "|";
	std::cout << DISABLE_ALL_FORMAT; //---------- Ending color
	std::cout << std::setw(MARGIN_WIDTH) << std::setfill(' ') << "" << std::endl << std::endl << std::endl;
}

//content  seeparation line
void Cl_ui::seperation_line() {

	std::cout << BORDER_LINE; //---------- starting color
	std::cout << std::setw(MARGIN_WIDTH) << std::setfill(' ') << "" << "|" << std::setw(TEXT_START_GAP) << std::setfill(' ') << "";	//---------- starting text locatiion

	std::cout << std::setw(TOTAL_WRITING_AREA) << std::setfill('~') << "";

	std::cout << std::setw(TEXT_START_GAP) << std::setfill(' ') << "" << "|";
	std::cout << DISABLE_ALL_FORMAT; //---------- Ending color
	std::cout << std::setw(MARGIN_WIDTH) << std::setfill(' ') << "";

}

//table row separation line
void Cl_ui::table_line(const char&& line_stle) {

	std::cout << std::setw(MARGIN_WIDTH + TEXT_START_GAP + 1) << std::setfill(' ') << "";	//---------- starting text ocatiion

	std::cout << std::setw(12 + INTER_COLUMN_GAP) << std::setfill(line_stle) << line_stle << "|";
	std::cout << std::setw(20 + INTER_COLUMN_GAP + INTER_COLUMN_GAP) << std::setfill(line_stle) << line_stle << "|";
	std::cout << std::setw(10 + INTER_COLUMN_GAP + INTER_COLUMN_GAP) << std::setfill(line_stle) << line_stle << "|";
	std::cout << std::setw(20 + INTER_COLUMN_GAP + INTER_COLUMN_GAP) << std::setfill(line_stle) << line_stle << "|";

	std::cout << std::setw(20) << std::setfill(line_stle) << "" << std::endl; //----------------- last column line end
}

void Cl_ui::employee_profile(SACommand* profile_data){

	this->heading("Viewing Employee Profile");

	int col_count = profile_data->FieldCount();
	profile_data->FetchFirst();

	for (int i = 1; i <= col_count; i++) {

		int col_name_length = std::strlen(profile_data->Field(i).Name());
		int col_value_lenggth = std::strlen(profile_data->Field(i).asString());

		std::cout << std::setw(MARGIN_WIDTH + TEXT_START_GAP + 1) << std::setfill(' ') << "";	//---------- starting text ocatiion

		std::cout.write(profile_data->Field(i).Name(), col_name_length); //------------- Column Name Printing

		std::cout << std::setw(((TOTAL_WRITING_AREA / 2) - 1) - col_name_length) << std::setfill(' ') << "" << ":"; //--------- ':' printing length
		std::cout << std::setw((TOTAL_WRITING_AREA / 2) - col_value_lenggth) << std::setfill(' ') << ""; //----------  white space before column value printing
		std::cout.write(profile_data->Field(i).asString(), col_value_lenggth); //----------- column value prnting;

		//printf("%-40s:%59s\n", profile_data->Field(i).Name(), profile_data->Field(i).asString());
		std::cout << std::endl << std::endl;
	}

	std::cout << std::endl;

	this->seperation_line();
}

//text starting gap creation
void Cl_ui::start_margin(const char&& padding_stle, const char&& margin_end_style, const char&& order= 'f') {//--- order not 'r' then MARGIN_WIDTH > TEXT_START_GAP else order 'r' printin reverse order

	int first_gap_length = MARGIN_WIDTH;
	int second_gap_length = TEXT_START_GAP;

	if (order == 'r') {
		int temp_value = first_gap_length;
		first_gap_length = second_gap_length;
		second_gap_length = temp_value;
	}

	std::cout << std::setw(first_gap_length) << std::setfill(padding_stle) << "" << margin_end_style << std::setw(second_gap_length) << std::setfill(padding_stle) << "";
}

void Cl_ui::ask_for_input(const std::string&& text_to_ask, const char&& end_style, const char&& printing_mode) {//---- 'f' means take total TEXT_PRINTING_AREA, 'h' means half

	int quection_area = ((TOTAL_WRITING_AREA / 2) - 1) - text_to_ask.length();

	if (printing_mode == 'f') {

		quection_area = 0;
	}

	this->start_margin(' ', ' ', 'f');
	std::cout << text_to_ask;
	std::cout << std::setw(quection_area) << std::setfill(' ') << "" << end_style; //--------- ':' printing length

}
