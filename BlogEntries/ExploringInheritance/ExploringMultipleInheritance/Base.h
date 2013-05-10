#pragma once

typedef struct Base_t Base;

typedef struct BaseTable_t
{
	void (*print)(Base *_this);
} BaseTable;

typedef struct BaseData_t
{
	int baseMember;
} BaseData;

typedef struct Base_t
{
	BaseTable *vfptr;
	BaseData data;
} Base;

void BaseConstruct(Base *base, int baseMember);
void BaseDesturct(Base *base);
