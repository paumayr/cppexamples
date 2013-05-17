#include "MyDoSomething.hpp"

#include <iostream>


void MyDoSomething::PrintSomething()
{
	std::cout << "Hello World from static lib" << std::endl;
}

IDoSomething * createDoSomething()
{
	return new MyDoSomething();
}
