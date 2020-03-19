#include "Cl_ui.h"

#include <iostream>

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

void Cl_ui::main_menu() {
	std::cout<<BORDER_LINE<<"   |     ~~~~~~~~~~~~~~~~~~           "<<HEADING_TEXT<<"Main Menu"<<BORDER_LINE<<"            ~~~~~~~~~~~~~~~~~~     |"<<DISABLE_ALL_FORMAT;
}