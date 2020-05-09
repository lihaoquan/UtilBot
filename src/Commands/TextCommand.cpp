#include "TextCommand.h"

void TextCommand::Execute(Application& app)
{
	CORE_INFO("[TextCommand] {0}", GetCommandName());
	if (op) {
		op->Do(app);
		CORE_INFO("[Operation] {0}", op->GetOperationName());
	}
	else {
		CORE_WARN("[Operation] No Operation Associated to {0}", GetCommandName());
	}
}