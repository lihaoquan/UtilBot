#pragma once

#include "../Operation.h"

class ExitOperation 
	: public Operation
{
public:
	ExitOperation(std::string name)
		: Operation(name) {}

	void Do(Application& app) override;
};