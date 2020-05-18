#include "Bot.h"


int main(int argc, char** argv) {

	srand(time(NULL));

	UtilBot::Bot* app = new UtilBot::Bot;
	app->Start();

	while (app->appRunning) {

		app->GetUserInput();

		app->ProcessCommand();

		Sleep(1);
	}

	delete app;

	return 0;
}