#include "Core.h"
#include <iostream>

int main(int argc, char** argv) {

	// Create an instance of the app
	UtilBot::App* app = new UtilBot::App;
	// Initialize app
	app->Start();

	TextCommand* A = new TextCommand("CommandA");
	app->AddCommand(A);

	TextCommand* B = new TextCommand("CommandB");
	app->AddCommand(B);

	// TODO if command matches command name, it handles it and executes the function.

	while (app->appRunning) {
		std::cin >> app->command;
		app->ProcessCommand();

		app->appRunning = false;

		Sleep(1);
	}

	delete app;

	std::cin;
	
	return 0;
}