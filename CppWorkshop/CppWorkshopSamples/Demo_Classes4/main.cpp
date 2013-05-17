// This code is INCORRECT and used for DEMONSTRATION purposes only
#include <iostream>
class Cat {
public:
	int age;
	void meauw() 
	{ 
		std::cout << "I am " << age << " years old! Meauw!!" << std::endl;
	}
};

int main(int argc, char **argv)
{
	Cat ticky;
	ticky.meauw(); // whoops, ticky.age is not initialized yet
	ticky.age = 18;
	return 0;
}