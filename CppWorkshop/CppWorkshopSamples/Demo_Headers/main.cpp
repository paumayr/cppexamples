#include <iostream>
#include "SomeClass.hpp"

int main(int argc, char **argv)
{
	SomeClass c(10);
	std::cout << "c.getMember() returned : " << c.getMember() << std::endl;
	return 0;
}
