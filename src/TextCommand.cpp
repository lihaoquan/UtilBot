#include "TextCommand.h"
#include <iostream>

void TextCommand::Execute() {
	std::cout << command_name << "Executed" << std::endl;
}