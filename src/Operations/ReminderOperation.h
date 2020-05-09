#pragma once

#include "../Operation.h"

class ReminderOperation
	: public Operation
{
public:
	ReminderOperation(std::string name)
		: Operation(name) {}

	void Do(Application& app) override;
};