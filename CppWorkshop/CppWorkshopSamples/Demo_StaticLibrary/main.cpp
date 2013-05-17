#include <memory>
#include <iostream>
#include "../Demo_StaticLibrary_Lib/MyDoSomething.hpp"

int main(int argc, char ** argv)
{
	typedef std::tr1::shared_ptr<IDoSomething> DoSomethingPtr;

	std::cout << "creating new instance of MyDoSomething" << std::endl;
	DoSomethingPtr doSomething = DoSomethingPtr(new MyDoSomething());
	doSomething->PrintSomething();

	return 0;
}