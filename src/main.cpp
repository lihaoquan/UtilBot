#include "Core.h"

#include <windows.h>
#include <mmsystem.h>

int main() {

	// Create an instance of the app
	UtilBot::App app = UtilBot::App::Get();
	app.Start();

	PlaySoundA((LPCSTR)"D:\\test.wav", NULL, SND_FILENAME | SND_ASYNC);
	getchar();

	return 0;
}