

#include <windows.h>
#include "IDoSomething.hpp" 
#include <string>

// module handle to the dll
HMODULE library;
// function pointers to create and destroy method

extern "C" {
typedef  IDoSomething * (*CreateDoSomething)(void);
CreateDoSomething createDoSomething;
typedef void (*DestroyDoSomething)(IDoSomething *something);
DestroyDoSomething destroyDoSomething;

}

void loadlibrary(std::string path)
{
	library = LoadLibraryA(path.c_str());
	createDoSomething = (CreateDoSomething)GetProcAddress(library, "createDoSomething");
	destroyDoSomething = (DestroyDoSomething)GetProcAddress(library, "destroyDoSomething");
}

void unloadLibrary()
{
	createDoSomething = 0;
	destroyDoSomething = 0;
	FreeLibrary(library);
}


int main(int argc, char **argv)
{

	loadlibrary("Demo_DynamicLibrary_Lib.dll");

	IDoSomething *doSomething = createDoSomething();

	doSomething->PrintSomething();

	// ERROR would delete on wrong heap!
	// delete doSomething;
	destroyDoSomething(doSomething);

	return 0;
}