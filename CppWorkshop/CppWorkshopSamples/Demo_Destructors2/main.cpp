#include <iostream>
#include <string>

class NoisyClass
{
	std::string name;
public:
	NoisyClass(const std::string& _name)
		: name(_name)
	{ 
		std::cout << "constructor called for " << name << std::endl;
	}

	~NoisyClass() 
	{
		std::cout << "destructor called for " << name << std::endl;
	}
};

NoisyClass *createAnotherNoisy()
{
	std::cout << "entering createAnotherNoisy" << std::endl;
	std::cout << "creating noisy object on heap within function" << std::endl;
	NoisyClass* p = new NoisyClass("b");

	std::cout << "returning pointer to another noisy object, no destructor called!" << std::endl;
	return p;
}

int main(int argc, char **argv)
{
	std::cout << "entering main" << std::endl;
	
	std::cout << "creating noisy object on heap" << std::endl;
	NoisyClass *pointerToA = new NoisyClass("a");
	delete pointerToA;
	std::cout << "destructed noisy object on heap" << std::endl;

	NoisyClass *pointerToB = createAnotherNoisy();
	std::cout << "got a pointer to a noisy object from function, deleting now!" << std::endl;
	delete pointerToB;
	std::cout << "exiting main" << std::endl;
}