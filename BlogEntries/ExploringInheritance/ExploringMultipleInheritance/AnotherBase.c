#include "AnotherBase.h"
#include <stdio.h>

AnotherBaseTable anotherBaseTable;

void AnotherBaseScan(AnotherBase *_this)
{
	printf("AnotherBase::scan, anotherBaseMember = %d\n", _this->data.anotherBaseMember);
}

void AnotherBaseConstruct(AnotherBase *_this, int anotherBaseMember)
{
	// TODO move to static initialization
	anotherBaseTable.scan = AnotherBaseScan;

	_this->vptr = &anotherBaseTable;
	_this->data.anotherBaseMember = anotherBaseMember;
}

void AnotherBaseDestruct(AnotherBase *_this)
{
}
