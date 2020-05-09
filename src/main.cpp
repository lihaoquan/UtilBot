﻿#include "Bot.h"
#include <string>
#include <iostream>
#include <codecvt>

int main(int argc, char** argv) {
	
	SetConsoleOutputCP(CP_UTF8);

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