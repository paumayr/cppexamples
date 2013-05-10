
#include "Derived.h"
#include <stdio.h>

DerivedTable derivedTable;

void DerivedPrint(Derived *_this)
{
	printf("Derived::print, baseMember = %d, derivedMember = %d\n", _this->base.baseMember, _this->data.derivedMember);
}

void DerivedReadFromFile(Derived *_this)
{
	printf("Derived::readFromFile");
}

void DerivedConstruct(Derived *_this, int baseMember, int derivedMember)
{
	// TODO move this to static initialization code
	derivedTable.print = DerivedPrint;
	derivedTable.readFromFile = DerivedReadFromFile;

	BaseConstruct((Base*)_this, baseMember);

	_this->vfptr = &derivedTable;
	_this->data.derivedMember = derivedMember;
}

void DerivedDestroy(Derived *_this)
{
	BaseDestroy((Base*)_this);
}

