#include "PrintSumCommand.hpp"
#include <iostream>

PrintSumCommand::PrintSumCommand(int _a, int _b)
: a(_a), b(_b)
{
}

void PrintSumCommand::execute() const
{
	std::cout << a << " + " << b << " is " << (a + b) << std::endl;
}