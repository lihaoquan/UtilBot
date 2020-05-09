#pragma once

#include "../Command.h"

class TextCommand :
	public Command
{
public:
	TextCommand(std::string name) 
		: Command(name) {}

	void Execute(Application& app) override;
};