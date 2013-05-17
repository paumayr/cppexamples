
#include <iostream>

#include "../Demo_DynamicLibrary/IDoSomething.hpp"

class MyDoSomething : public IDoSomething
{
public:
	virtual void PrintSomething() {
		std::cout << "hello world from dll" << std::endl;
	};
};

extern "C" __declspec(dllexport) IDoSomething * createDoSomething()
{
	return new MyDoSomething();
}


extern "C" __declspec(dllexport) void destroyDoSomething(IDoSomething *something)
{
	delete something;
}


