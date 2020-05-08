#include "Core.h"
#include <iostream>

#include "MySQL.h"


int main(int argc, char** argv) {

	// Create an instance of the app
	UtilBot::App* app = new UtilBot::App;
	// Initialize app
	app->Start();

	app->AddCommand(new TextCommand("CommandA"));
	app->AddCommand(new TextCommand("CommandB"));

	MySQL sql;
	sql.Init();

	sql.Execute();
	sql.Execute();

	/*while (app->appRunning) {

		std::getline(std::cin, app->command);

		app->ProcessCommand();

		app->appRunning = false;

		Sleep(1);
	}

	delete app;*/

	std::cin;
	
	return 0;
}