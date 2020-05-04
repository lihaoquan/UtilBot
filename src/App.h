#pragma once

#include "Log.h"

namespace UtilBot {
	class App
	{
	public:
		App();
		~App();
		void Start();
		void ProcessCommand();
		char* command;
		bool appRunning;
	};
}

