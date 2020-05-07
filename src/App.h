#pragma once

#include "Log.h"
#include "Command.h"

namespace UtilBot {
class App
	{
	public:
		App();
		~App();
		void Start();
		void ProcessCommand();
		std::string command;
		bool appRunning;
		void AddCommand(Command* c);
	private:
		std::vector<std::unique_ptr<Command>> availableCommands;
	};
}

