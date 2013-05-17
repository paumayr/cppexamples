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

void someFunction()
{
	std::cout << "entering function" << std::endl;
	NoisyClass c("c");
	std::cout << "exiting function" << std::endl;
}

int main(int argc, char **argv)
{
	std::cout << "entering main" << std::endl;

	NoisyClass a("a");

	{
		std::cout << "opened new scoped" << std::endl;
		NoisyClass b("b");

		someFunction();

		std::cout << "closing scope" << std::endl;
	}

	std::cout << "exiting main" << std::endl;
}