#include "ConsoleCallback.hpp"
#include <iostream>

void ConsoleCallback::onScanStarted()
{
	std::cout << "scan started" << std::endl;
}

void ConsoleCallback::onVirusFound()
{
	std::cout << "found a virus" << std::endl;
}

void ConsoleCallback::onScanFinished()
{
	std::cout << "scan finished" << std::endl;
}
