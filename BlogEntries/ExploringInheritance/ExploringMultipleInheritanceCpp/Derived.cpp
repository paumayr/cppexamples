#include "Derived.hpp"
#include <iostream>

Derived::Derived(int baseMember, int anotherBaseMember)
	: Base(baseMember), AnotherBase(anotherBaseMember)
{
}

Derived::~Derived()
{
}

void Derived::readFromFile()
{
	std::cout << "Derived::readFromFile" << std::endl;
}
