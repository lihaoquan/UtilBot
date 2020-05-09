#pragma once

#include <string>
#include "Log.h"
#include "Operation.h"
#include "Application.h"

class Command
{
protected:
	std::string command_name = 0;
	Operation* op = nullptr;
public:
	Command(std::string name) :
		command_name(name) {}

	~Command() {
		delete op;
	}

	std::string GetCommandName() {
		return command_name;
	}

	Command* SetOperation(Operation* o) {
		op = o;
		return this;
	}

	virtual void Execute(Application& app) = 0;
};