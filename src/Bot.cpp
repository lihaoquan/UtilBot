#include "Bot.h"

namespace UtilBot {

	Bot::~Bot() {
		for (Command* c : availableCommands) delete c;
		availableCommands.clear();
	}

	void Bot::Start() {

		srand(time(NULL));

		SetConsoleOutputCP(CP_UTF8);

		Log::Init();
		
		InitCommands();

		mysql.Init("UtilBot", "root", "");
		
		CORE_WARN("App Initialized.");
	}

	void Bot::GetUserInput()
	{
		std::getline(std::cin, this->command);

		std::vector<std::string> args;
		std::istringstream iss(this->command);

		unsigned i = 0;
		for (std::string s; iss >> s;) {
			if (i != 0) args.push_back(s);
			else this->command = s;
			++i;
		}

		this->args = args;
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