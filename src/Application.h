#pragma once

#include <string>

class Application {
public:
	bool appRunning;
	virtual void Start() = 0;
	std::vector<std::string> args;
};