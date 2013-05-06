#include "Base.h"
#include <stdio.h>

BaseTable baseTable;

void BasePrint(Base *_this)
{
	printf("Base::print, baseMember = %d\n", _this->baseMember);
}

void BaseConstruct(Base *_this, int baseMember)
{
	// TODO move this to static initialization code
	baseTable.print = &BasePrint;

	_this->vfptr = &baseTable;
	_this->baseMember = baseMember;
}

void BaseDestroy(Base *_this)
{
}

