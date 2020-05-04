#include "Core.h"
#include <iostream>

int main(int argc, char** argv) {

	// Create an instance of the app
	UtilBot::App* app = new UtilBot::App;
	// Initialize app
	app->Start();

	TextCommand c("command");
	c.Execute();

	// TODO if command matches command name, it handles it and executes the function.

	while (app->appRunning) {
		std::cin >> app->command;
		app->ProcessCommand();
		Sleep(1);
	}

	delete app;
	std::cin;
	return 0;
}