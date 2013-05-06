
#include "Derived.h"
#include <stdio.h>

DerivedTable derivedTable;

void DerivedPrint(Derived *_this)
{
	printf("Derived::print, baseMember = %d, derivedMember = %d\n", _this->base.baseMember, _this->derivedMember);
}

void DerivedConstruct(Derived *_this, int baseMember, int derivedMember)
{
	// TODO move this to static initialization code
	derivedTable.baseTable.print = (void (*)(struct Base *))DerivedPrint;

	BaseConstruct(&_this->base, baseMember);

	_this->base.vfptr = (BaseTable*)&derivedTable;
	_this->derivedMember = derivedMember;
}

void DerivedDestroy(Derived *_this)
{
	BaseDestroy((Base*)_this);
}

