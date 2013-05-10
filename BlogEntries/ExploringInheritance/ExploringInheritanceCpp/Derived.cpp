
#include "Derived.hpp"
#include <iostream>

Derived::Derived(int derivedMember, int baseMember)
	: Base(baseMember),
	derivedMember(derivedMember)
{
}

Derived::~Derived()
{
}

void Derived::print()
{
	std::cout << "Derived::print, baseMember = " << getBaseMember() << ", derivedMember = " << derivedMember << std::endl;
}

void Derived::readFromFile()
{
	std::cout << "Derived::readFromFile" << std::endl;
}
