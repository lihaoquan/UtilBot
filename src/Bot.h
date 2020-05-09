#pragma once

#include "Core.h"
#include "Application.h"

namespace UtilBot {
class Bot : public Application
	{
	public:
		~Bot();
		void Start() override;
		void ProcessCommand();
		std::string command;
		void AddCommand(Command* c);
	private:
		std::vector<Command*> availableCommands;
		MySQL mysql;
		void InitCommands();
	};
}