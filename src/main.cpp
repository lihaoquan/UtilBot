#include "Core.h"
#include <iostream>

int main(int argc, char** argv) {

	// Create an instance of the app
	UtilBot::App* app = new UtilBot::App;
	// Initialize app
	app->Start();

	app->AddCommand(new TextCommand("CommandA"));
	app->AddCommand(new TextCommand("CommandB"));

	while (app->appRunning) {

		std::getline(std::cin, app->command);

		app->ProcessCommand();

		app->appRunning = false;

		Sleep(1);
	}

	delete app;

	std::cin;
	
	return 0;
}