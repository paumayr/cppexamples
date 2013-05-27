
#include <iostream>

int main(int argc, char **argv)
{
	int a = 10;
	int &refA = a;
	int *ptrA = &a;

	// a refers to the same object
	std::cout << "a = " << a << " refA = " << refA << std::endl;
	// changing the value of the reference, changes the referenced object
	refA = 12;
	
	std::cout << "a = " << a << " refA = " << refA << std::endl;

	int b = 50;
	// you cannot change the reference to a different object,
	// the referenced object is changed instead
	refA = b;
	std::cout << "a = " << a << " refA = " << refA << " b = " << b << std::endl;
	// refA still references A, not b
	b = 60;
	std::cout << "a = " << a << " refA = " << refA << " b = " << b << std::endl;

	int * pointerRefA = &refA;
	int * pointerA = &a;
	std::cin.get();

	int * arr = new int[100000];
	int &refArr0 = arr[0];

	return 0;
}