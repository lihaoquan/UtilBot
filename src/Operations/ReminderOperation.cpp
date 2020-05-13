#include "ReminderOperation.h"

void ReminderOperation::Do(Application& app) {

	if (app.args.size() < 3) {
		CORE_ERROR("Insufficient Arugments for {0}", this->GetOperationName());
	}
	else {

		std::string date = app.args[0];
		std::string time = app.args[1];

		std::regex regex("\\-");

		std::vector<std::string> date_split(
			std::sregex_token_iterator(date.begin(), date.end(), regex, -1),
			std::sregex_token_iterator()
		);

		date = date_split[2] + "-" + date_split[1] + "-" + date_split[0];
		std::string datetime = date + " " + time;

		std::string reminder_text;

		for (int i = 2; i < app.args.size(); i++) {
			CORE_INFO("App Argument {0}: {1}", (i + 1), app.args[i]);
			reminder_text += app.args[i] + " ";
		}
		
		CORE_INFO("Reminder Text: {0}", reminder_text);

		std::vector<std::string> statements;

		statements.push_back("INSERT INTO `reminders` (`datetime`, `text`) VALUES ('" + datetime + "', '" + reminder_text + "');");
		
		app.mysql.Execute(statements);

		// TODO insert into DB and have a function to retrieve at an interval, reminders with time that are < current time, and are not processed (bool).
	}
}