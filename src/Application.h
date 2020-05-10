#pragma once

#include <string>
#include <vector>

class Application {
public:
	bool appRunning;
	virtual void Start() = 0;
	std::vector<std::string> args;
};