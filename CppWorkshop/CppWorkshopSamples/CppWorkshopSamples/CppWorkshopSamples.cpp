// CppWorkshopSamples.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>
#include <vector>
#include <list>
using namespace std;

int Circumference(int w, int h) 
{ 
  return 2 * (w + h); 
}

int Circumference(int side) // different function!
{ 
  return 4 * side;
}
/*
double Circumference(int w, int h) // wrong, redefinition with different return type!)
{
  return 2 * (w + h);
}
*/

/*
int main(int argc, char **argv)
{
	// pointer to a single integer on the heap
	int* myIntegerPointer = new int;
	// dereference the pointer and assign a value.
	*myIntegerPointer = 8;
	// free the integer on the heap
	delete myIntegerPointer;

	// variable on the stack
	int i = 10;
	// get the pointer to i
	myIntegerPointer = &i;
	// modify i
	*myIntegerPointer = 12;
	// i is now = 12
}
*/
/*
int main(int argc, char **argv)
{
	std::vector<int> v1;
	v1.push_back(10); v1.push_back(12); v1.push_back(14); v1.push_back(16);
	std::vector<int> v2;
	v2.push_back(10); v2.push_back(12); v2.push_back(14); v2.push_back(16);
	std::vector<int> v3;
	v3.push_back(11); v3.push_back(13); v3.push_back(15); v3.push_back(17);

	if (v1 == v2) {
		std::cout << "v1 == v2" << std::endl;
	} else {
		std::cout << "v1 != v2" << std::endl;
	}

	if (v1 == v3) {
		std::cout << "v1 == v3" << std::endl;
	} else {
		std::cout << "v1 != v3" << std::endl;
	}

	v2.swap(v3);
	
	if (v1 == v3) {
		std::cout << "v1 == v3" << std::endl;
	} else {
		std::cout << "v1 != v3" << std::endl;
	}

	if (v1 < v2) {
		std::cout << "v1 < v2" << std::endl;
	} else	{
		std::cout << "v1 >= v2" << std::endl;
	}

	std::cin.get();
}
*/

int main(int argc, char ** argv)
{
	typedef std::vector<int> ContainerType;

	ContainerType my_vector;

	my_vector.push_back(10);
	my_vector.push_back(12);
	my_vector.push_back(14);
	my_vector.push_back(16);

	for(ContainerType::iterator  it = my_vector.begin();
		it != my_vector.end();
		it++)
	{
		int v = *it;
	}

	ContainerType b = my_vector;
}

