
#include <iostream>

#include "Singleton.hpp"
#include "Logger.hpp"

void foo()
{
	
	Singleton::Instance()->accessSharedResource();
}

int main(int argc, char **argv)
{
	Singleton::Instance()->accessSharedResource();


	foo();

	/*
	Logger::Instance().initialize("c:\\temp\\loggerdemo.log", 5);
	Logger::Instance().log(0, "ignored log message");
	Logger::Instance().log(10, "an entry");
	*/
	return 0;
}

