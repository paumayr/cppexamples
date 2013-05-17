
#include "SomeClass.hpp"

// definition of member functions
SomeClass::SomeClass(int _member)
: member(_member)
{
}

SomeClass::~SomeClass()
{
}

int SomeClass::getMember() const
{
	return member;
}
