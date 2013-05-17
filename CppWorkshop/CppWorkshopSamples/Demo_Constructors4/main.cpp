#include <iostream>
#include <string>
class Cat {
public:
	Cat()
	{
		Cat(18, "ticky");
	}

	Cat(int _age) : age(_age), name("ticky") {}
	Cat(int _age, std::string _name) : age(_age), name(_name)  {}

	std::string name;
	int age;
	void meauw() 
	{ std::cout << "I am " << age << " years old! Meauw!!" << std::endl; }
};

int main(int argc, char **argv)
{
	Cat ticky; // call default constructor
	ticky.meauw();
	return 0;
}
