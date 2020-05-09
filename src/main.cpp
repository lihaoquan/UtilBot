#include "Bot.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {

	// Create an instance of the app
	UtilBot::Bot* app = new UtilBot::Bot;

	// Initialize app
	app->Start();

	while (app->appRunning) {

		std::getline(std::cin, app->command);

		app->ProcessCommand();

		Sleep(1);
	}

	delete app;

	std::cin;
	
	return 0;
}