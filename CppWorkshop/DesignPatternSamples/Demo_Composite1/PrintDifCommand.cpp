#include "PrintDifCommand.hpp"
#include <iostream>

PrintDifCommand::PrintDifCommand(int _a, int _b)
: a(_a), b(_b)
{
}

void PrintDifCommand::execute() const
{
	std::cout << a << " - " << b << " is " << (a - b) << std::endl;
}