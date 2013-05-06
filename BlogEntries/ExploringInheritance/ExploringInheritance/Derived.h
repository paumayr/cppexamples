#pragma once

#include "Base.h"

typedef struct DerivedTable_t
{
	BaseTable baseTable;

} DerivedTable;

typedef struct Derived_t
{
	Base base;
	int derivedMember;
} Derived;

void DerivedConstruct(Derived *_this, int baseMember, int derivedMember);
void DerivedDestroy(Derived *_this);
