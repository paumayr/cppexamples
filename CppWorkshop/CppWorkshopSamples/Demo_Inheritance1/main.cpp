#include <iostream>
#include <string>

class Pet
{
	std::string name;
public:
	Pet(const std::string &_name) : name(_name)	{ }
	
	void speak() {
		std::cout << "I am " + name + " and can talk" << std::endl;
	}
};

class Cat : public Pet
{
public:
	Cat(const std::string& name) : Pet(name) {}
	void purr() {
		std::cout << "purrrrrrrrr" << std::endl;
	}
};

class Dog : public Pet
{
public:
	Dog(const std::string& name) : Pet(name) {}
	void pant()	{ // "hecheln"
		std::cout << "hechel, hechel (i'm a german dog)." << std::endl;
	}
};

int main(int argc, char **argv)
{
	Cat ticky("ticky");
	Dog spotty("spotty");

	// ok, both of them are pets
	spotty.speak();
	ticky.speak();

	// ticky is a cat an can purr
	ticky.purr();
	// potty is a dog, and can pant
	spotty.pant();
	// ERROR a cat can not pant
	//ticky.pant();
	// ERROR a dog cannot purr
	// spotty.purr();
}