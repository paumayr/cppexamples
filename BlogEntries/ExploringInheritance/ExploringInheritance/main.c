
#include "Base.h"
#include "Derived.h"


void printObject(Base *base)
{
	base->vfptr->print(base);
}

int main(int argc, char **argv)
{
	Base base;
	Derived derived;

	BaseConstruct(&base, 10);
	DerivedConstruct(&derived, 10, 20);

	printObject(&base);
	printObject(&derived.base);

	DerivedDestroy(&derived);
	BaseDestroy(&base);
	return 0;
}