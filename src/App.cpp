#include "App.h"
#include "Log.h"

namespace UtilBot {

	App::App() {
		appRunning = true;
		command = new char();
	}

	App::~App() {
		delete command;
	}

	void App::Start() {

		Log::Init();
		CORE_WARN("App Initialized.");
	}

	void App::ProcessCommand()
	{
		CORE_INFO("Command Received: {0}", command);
	}
}