#pragma once

#include "Base.h"

typedef struct Derived_t Derived;

typedef struct DerivedTable_t
{
	union
	{
		BaseTable baseFunctions;
		void (*print)(Derived* _this);
	};
	
	void (*readFromFile)(Derived* _this);
} DerivedTable;

typedef struct DerivedData_t
{
	int derivedMember;
} DerivedData;

typedef struct Derived_t
{
	DerivedTable *vfptr;
	BaseData base;
	DerivedData data;
} Derived;

void DerivedConstruct(Derived *_this, int baseMember, int derivedMember);
void DerivedDestroy(Derived *_this);
