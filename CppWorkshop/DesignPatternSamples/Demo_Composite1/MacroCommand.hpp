#pragma once
#include "Command.hpp"
#include <vector>
#include <memory>

class MacroCommand : public Command
{
	std::vector<std::shared_ptr<Command>> commands;
public:
	virtual void execute() const;

	void add(std::shared_ptr<Command> command);
	void remove(std::shared_ptr<Command> command);
};