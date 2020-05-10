#include "ReminderCommand.h"

void ReminderCommand::Execute(Application& app)
{
	CORE_INFO("[ReminderCommand] {0}", GetCommandName());
	if (op) {
		op->Do(app);
		CORE_INFO("[Operation] {0}", op->GetOperationName());
	}
	else {
		CORE_WARN("[Operation] No Operation Associated to {0}", GetCommandName());
	}
}
