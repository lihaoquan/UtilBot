#pragma once

#include <string>
#include "Log.h"
#include "Application.h"

class Operation
{
protected:
	std::string operation_name = 0;
public:
	Operation(std::string name) :
		operation_name(name) {}

	std::string GetOperationName() {
		return operation_name;
	}

	virtual void Do(Application& app) = 0;
};