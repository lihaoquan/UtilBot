#pragma once
class Command
{
public:
	Command(char* name) :
		command_name(name) {}
	char* GetCommandName() {
		return command_name;
	}
	virtual void Execute() = 0;
private:
	char* command_name;
};

