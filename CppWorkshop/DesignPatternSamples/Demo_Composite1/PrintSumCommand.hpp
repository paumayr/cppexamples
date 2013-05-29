
#pragma once
#include "Command.hpp"

class PrintSumCommand : public Command
{
	int a;
	int b;

public:
	PrintSumCommand(int a, int b);
	virtual void execute() const;
};
