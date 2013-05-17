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
	ticky.age = 18;
	ticky.meauw();

	Cat petzi;
	petzi.age = 6;
	petzi.meauw();
	return 0;
}