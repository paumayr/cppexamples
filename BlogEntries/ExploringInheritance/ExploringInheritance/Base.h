#pragma once 

typedef struct Base_t Base;

typedef struct BaseTable_t
{
	void (*print)(Base* _this);
	int x;
} BaseTable;

typedef struct Base_t
{
	BaseTable *vfptr;
	int baseMember;
} Base;

void BaseConstruct(Base *_this, int baseMember);
void BaseDestroy(Base *_this);
