#include <iostream>
#include "StaticHolder.hpp"


int main(int argc, char ** argv)
{
	// ERROR, cannot call a member function without an instance
	//StaticHolder::classicMemberFunction();
	
	// OK, static member function
	StaticHolder::staticMemberFunction();

	// OK static member access
	StaticHolder::staticMemberVariable++;

	// ERROR, cannot access a member variable without an instance
	// StaticHolder::classicMemberVariable = 30;

	StaticHolder instance;

	// OK, access using the instance
	instance.classicMemberVariable = 25;

	// valid, but very bad style.
	instance.staticMemberVariable = 30;
	// better:
	StaticHolder::staticMemberVariable++;

	// ok, access through instance.
	instance.classicMemberFunction();

	// valid, but very bad style
	instance.staticMemberFunction();
	// better:
	StaticHolder::staticMemberFunction();

	return 0;
}