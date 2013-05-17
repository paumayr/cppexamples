
#include "../Demo_DynamicLibrary/IDoSomething.hpp"

extern "C"
{	
extern "C" __declspec(dllexport) IDoSomething * createDoSomething();
extern "C" __declspec(dllexport) void destroyDoSomething(IDoSomething *something);
}

int main(int argc, char **argv)
{
	IDoSomething *p = createDoSomething();

	p->PrintSomething();

	destroyDoSomething(p);
}