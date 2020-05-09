#pragma once

#include "../Operation.h"
#include <iostream>

class GreetingsOperation
	: public Operation
{
public:
	GreetingsOperation(std::string name)
		: Operation(name) {}

	void Do(Application& app) override;
};