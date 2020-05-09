#include "Bot.h"

namespace UtilBot {

	Bot::~Bot() {
		for (Command* c : availableCommands) delete c;
		availableCommands.clear();
	}

	void Bot::Start() {

		Log::Init();
		
		// Add Commands
		InitCommands();

		// Initialize MySQL
		mysql.Init("UtilBot", "root", "");
		
		CORE_WARN("App Initialized.");
	}

	void Bot::ProcessCommand()
	{
		CORE_INFO("[Command] {0}", command);

		for (int i = 0; i < availableCommands.size(); i++) {
			if (availableCommands[i]->GetCommandName() == command) {
				availableCommands[i]->Execute(*this);
				break;
			}
		}
	}

	void Bot::AddCommand(Command* c)
	{
		availableCommands.push_back(c);
	}

	void Bot::InitCommands()
	{
		AddCommand((new TextCommand("hello"))->SetOperation(new GreetingsOperation("Bot Greetings")));
		AddCommand((new TextCommand("exit"))->SetOperation(new ExitOperation("Exit Program")));
		AddCommand((new TextCommand("hiragana"))->SetOperation(new Hiragana("Hiragana Test")));
		AddCommand((new ReminderCommand("reminder"))->SetOperation(new ReminderOperation("Create a Reminder")));	
	}
}