#pragma once

#include <string>

class Command
{
protected:
	std::string command_name = 0;
public:
	Command(std::string name) :
		command_name(name) {}

	std::string GetCommandName() {
		return command_name;
	}

	virtual void Execute() = 0;
};

