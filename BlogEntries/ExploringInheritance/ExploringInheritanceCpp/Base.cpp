#include "Base.hpp"

#include <iostream>

Base::Base(int baseMember)
	: baseMember(baseMember)
{
}

Base::~Base()
{
}

void Base::print()
{
	std::cout << "Base::print, baseMember = " << baseMember << std::endl;
}

int Base::getBaseMember() const
{
	return baseMember;
}