#pragma once

typedef struct AnotherBase_t AnotherBase;

typedef struct AnotherBaseTable_t
{
		void (*scan)(AnotherBase *_this);
} AnotherBaseTable;

typedef struct AnotherBaseData_t
{
	int anotherBaseMember;
} AnotherBaseData;

typedef struct AnotherBase_t
{
	AnotherBaseTable *vptr;
	AnotherBaseData data;
} AnotherBase;

void AnotherBaseConstruct(AnotherBase *_this, int anotherBaseMember);
void AnotherBaseDestruct(AnotherBase *_this);
