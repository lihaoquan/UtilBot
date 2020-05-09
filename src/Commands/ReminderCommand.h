#pragma once

#include "../Command.h"

class ReminderCommand :
	public Command
{
public:
	ReminderCommand(std::string name)
		: Command(name) {}

	void Execute(Application& app) override;
};