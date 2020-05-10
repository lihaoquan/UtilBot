#pragma once

#include <time.h>

#include "Core.h"
#include "Application.h"

namespace UtilBot {
class Bot : public Application
	{
	public:
		~Bot();
		void Start() override;
		void GetUserInput();
		void ProcessCommand();
		void AddCommand(Command* c);
		std::string command;
	private:
		void InitCommands();
		std::vector<Command*> availableCommands;
		MySQL mysql;
	};
}