#include "AnotherBase.hpp"
#include "Base.hpp"
#include "Derived.hpp"

void printBase(Base &base)
{
	base.print();
}

void printAnotherBase(AnotherBase &anotherBase)
{
	anotherBase.scan();
}

int main(int argc, char **argv)
{
	Base base(10);
	AnotherBase anotherBase(20);
	Derived derived(30, 40);

	printBase(base);
	printBase(derived);

	printAnotherBase(anotherBase);
	printAnotherBase(derived);

	return 0;
}