#pragma once

#include "Base.hpp"

class Derived : public Base
{
public:
	int derivedMember;

	Derived(int derivedMember, int baseMember);
	virtual ~Derived();

	virtual void print();
	virtual void readFromFile();
};