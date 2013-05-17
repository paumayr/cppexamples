#include <iostream>
class Cat {
public:
	Cat() // supply a default constructor
	{
		std::cout << "age : " << age << std::endl;
		age = 18;
	}

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
