#pragma once
#include "AnotherBase.h"
#include "Base.h"

typedef struct Derived_t Derived;

typedef struct DerivedTable_t
{
	union
	{
		BaseTable baseFunctions;
		void (*printBase)(Derived *_this);
	};

	void (*readFromFile)(Derived *_this);
} DerivedTable;

typedef struct DerivedData_t
{
	int derivedMember;
} DerivedData;

typedef struct Derived_t
{
	DerivedTable *vfptrDerived;
	BaseData baseData;

	AnotherBaseTable *vfptrAnotherBase;
	AnotherBaseData anotherBaseData;

	DerivedData derivedData;
} Derived;


void DerivedConstruct(Derived *derived, int baseMember, int anotherBaseMember, int derivedMember);
void DerivedDestruct(Derived *derived);
