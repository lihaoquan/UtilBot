#pragma once

#include "Log.h"

namespace UtilBot {
	class App
	{
	private:
		App() {}
	public:
		~App() {}
		static App& Get() {
			App instance;
			return instance;
		}
		void Start();
	};
}

