#include "Base.h"
#include "AnotherBase.h"
#include "Derived.h"

void callScan(AnotherBase *anotherBase)
{
	anotherBase->vptr->scan(anotherBase);
}

void callPrint(Base *base)
{
	base->vfptr->print(base);
}

int main(int argc, char **argv)
{
	Base base;
	AnotherBase anotherBase;
	Derived derived;

	BaseConstruct(&base, 10);
	AnotherBaseConstruct(&anotherBase, 20);
	DerivedConstruct(&derived, 30, 40, 50);

	callPrint(&base);
	callPrint((Base*)&derived);

	callScan(&anotherBase);
	callScan((AnotherBase*)&derived.vfptrAnotherBase);

	return 0;
}