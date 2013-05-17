#include "StaticHolder.hpp"

// define static members in one cpp file like this
int StaticHolder::staticMemberVariable = 5;

void StaticHolder::staticMemberFunction()
{
	// can only access static members,
	// note: no this pointer here
	// ERROR
	// classicMemberVariable = 3;
	// OK
	staticMemberVariable++;
}

void StaticHolder::classicMemberFunction()
{
	// can access static and non static members
	classicMemberVariable++;
	staticMemberVariable++;

 // works, but is confusing
	this->staticMemberVariable = 10;
}