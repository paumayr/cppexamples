#include <iostream>
class Cat {
public:
	void meauw() { std::cout << "Meauw!!" << std::endl; }
};

int main(int argc, char **argv)
{
	Cat ticky;
	ticky.meauw();
	return 0;
}