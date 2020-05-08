#include "App.h"

namespace UtilBot {

	App::App() {
		appRunning = true;
	}

	App::~App() {
		for (Command* c : availableCommands) delete c;
		availableCommands.clear();
	}

	void App::Start() {

		Log::Init();
		CORE_WARN("App Initialized.");
	}

	void App::ProcessCommand()
	{
		CORE_INFO("Command Received: {0}", command);

		for (int i = 0; i < availableCommands.size(); i++) {
			if (availableCommands[i]->GetCommandName() == command) {
				availableCommands[i]->Execute();
				break;
			}
		}
	}

	void App::AddCommand(Command* c)
	{
		availableCommands.push_back(c);
	}
}