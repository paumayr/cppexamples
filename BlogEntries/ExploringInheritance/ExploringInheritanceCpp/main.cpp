
#include "Base.hpp"
#include "Derived.hpp"

void PrintObject(Base &ptrBase)
{
	ptrBase.print();
}

int main(int argc, char **argv)
{
	Base base(10);
	Derived derived(10, 20);
	PrintObject(base);
	PrintObject(derived);
}