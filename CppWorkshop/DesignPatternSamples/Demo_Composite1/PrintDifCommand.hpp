#pragma once

#include "Command.hpp"

class PrintDifCommand : public Command
{
	int a, b;
public:
	PrintDifCommand(int _a, int _b);
	virtual void execute() const;
};