
#include "Person.h"

Person::Person()
{
}

Person::~Person()
{
}

void Person::setFirstName(const std::string& firstName)
{
	this->firstName = firstName;
}

const std::string& Person::getFirstName() const
{
	return this->firstName;
}

void Person::setLastName(const std::string& lastName)
{
	this->lastName = lastName;
}

const std::string& Person::getLastName() const
{
	return this->lastName;
}

std::string Person::getFullName() const
{
	return this->lastName + ", " + this->firstName;
}