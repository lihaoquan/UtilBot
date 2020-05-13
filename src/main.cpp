#include "Bot.h"

#include <io.h>
#include <fcntl.h>

int main(int argc, char** argv) {

	srand(time(NULL));
	_setmode(_fileno(stdout), _O_U16TEXT);

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