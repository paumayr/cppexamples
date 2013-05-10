#pragma once 

#include "Base.hpp"
#include "AnotherBase.hpp"

class Derived : public Base, public AnotherBase
{
public:
	Derived(int baseMember, int anotherBaseMember);
	virtual ~Derived();

	virtual void readFromFile();
};