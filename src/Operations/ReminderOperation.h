#pragma once

#include <string>

#include "../Operation.h"
#include "../TimeManager.h"

class ReminderOperation
	: public Operation
{
private:
	TimeManager timeManager;
public:
	ReminderOperation(std::string name)
		: Operation(name) {}

	void Do(Application& app) override;
};