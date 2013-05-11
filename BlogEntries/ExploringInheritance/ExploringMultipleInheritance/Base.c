#include "Base.h"
#include <stdio.h>

BaseTable baseTable;

void BasePrint(Base *_this)
{
	printf("Base::print, baseMember = %d\n", _this->data.baseMember);
}

void BaseConstruct(Base *_this, int baseMember)
{
	// TODO move to static initialization
	baseTable.print = BasePrint;

	_this->vfptr = &baseTable;
	_this->data.baseMember = baseMember;
}

void BaseDesturct(Base *_this)
{
}