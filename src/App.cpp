#include "App.h"
#include "Log.h"

namespace UtilBot {
	
	void App::Start() {

		Log::Init();
		CORE_WARN("App Initialized.");
	
	}
}