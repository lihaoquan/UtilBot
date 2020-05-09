#include "ExitOperation.h"

void ExitOperation::Do(Application& app) {
	app.appRunning = false;
}