#include "MacroCommand.hpp"
#include <algorithm>

using namespace std;
using namespace std::tr1;

void MacroCommand::execute() const
{
	typedef shared_ptr<Command> CommandPtr;
	typedef vector<CommandPtr> CommandPtrVector;
	for(CommandPtrVector::const_iterator i = commands.begin(); i != commands.end(); ++i)
	{
		(*i)->execute();
	}
}

void MacroCommand::add(shared_ptr<Command> command)
{
	commands.push_back(command);
}

void MacroCommand::remove(shared_ptr<Command> command)
{
	// removes the command element from the commands list.
	commands.erase(std::remove(commands.begin(), commands.end(), command), commands.end());
}