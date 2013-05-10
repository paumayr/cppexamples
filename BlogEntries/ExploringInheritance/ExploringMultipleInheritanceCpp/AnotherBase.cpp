#include "AnotherBase.hpp"
#include <iostream>

AnotherBase::AnotherBase(int anotherBaseMember)
	: anotherBaseMember(anotherBaseMember)
{
}

AnotherBase::~AnotherBase()
{
}

void AnotherBase::scan()
{
	std::cout << "AnotherBase::printAnother, baseMember = " << anotherBaseMember << std::endl;
}
