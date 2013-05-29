#include <iostream>
class Cat {
public:
	Cat() 
		: age(0)
	{
		std::cout << age << std::endl;
	}

	Cat(int _age)  // constructors have the same name as the class 
	{
		age = _age;
	}

	int age;
	void meauw() 
	{ std::cout << "I am " << age << " years old! Meauw!!" << std::endl; }
};

int main(int argc, char **argv)
{
	//Cat petzi;

	Cat petzi;

	Cat ticky(18); // intialization arguments are passed to constructor
	ticky.meauw();
	return 0;
}
