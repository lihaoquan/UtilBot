#pragma once
#include "Command.h"
class TextCommand :
	public Command
{
public:
	TextCommand(char* name) 
		:Command(name) {}
	void Execute() override;
};

