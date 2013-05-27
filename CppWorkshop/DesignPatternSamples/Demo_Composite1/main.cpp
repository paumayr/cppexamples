
#include <memory>
#include <iostream>

#include "PrintSumCommand.hpp"
#include "PrintDifCommand.hpp"
#include "MacroCommand.hpp"

using namespace std;
int main(int argc, char **argv)
{
	typedef std::tr1::shared_ptr<Command> CommandPtr;
	typedef std::tr1::shared_ptr<MacroCommand> MacroCommandPtr; 
	
	CommandPtr sum52 = CommandPtr(new PrintSumCommand(5, 2)); 
	CommandPtr sum105 = CommandPtr(new PrintSumCommand(10, 5));
	MacroCommandPtr macroCommand = MacroCommandPtr(new MacroCommand());
	CommandPtr difCmd = CommandPtr(new PrintDifCommand(10, 3));


	macroCommand->add(sum52);
	macroCommand->add(sum105);
	macroCommand->add(difCmd);

	std::cout << "executing macro command with both" << std::endl;
	macroCommand->execute();
	std::cout << "done executing macro command with both" << std::endl;

	macroCommand->remove(sum52);

	std::cout << "executing macro command with only one" << std::endl;
	macroCommand->execute();
	std::cout << "done executing macro command with only one." << std::endl;

	MacroCommandPtr macroCommand2 = MacroCommandPtr(new MacroCommand());

	macroCommand2->add(macroCommand);
	macroCommand2->add(macroCommand);

	macroCommand2->execute();

	return 0;
}