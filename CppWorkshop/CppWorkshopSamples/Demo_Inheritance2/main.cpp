
#include <iostream>
#include <string>

class Pet
{
	std::string name;
public:
	Pet(const std::string &_name) : name(_name)	{ }
	
	virtual void speak() {
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

	virtual void speak() {
		std::cout << "meeeeaaauuwww" << std::endl;
	}
};

class Dog : public Pet
{
public:
	Dog(const std::string& name) : Pet(name) {}
	void pant()	{ // "hecheln"
		std::cout << "hechel, hechel (i'm a german dog)." << std::endl;
	}

	virtual void speak() {
		std::cout << "woof. woof." << std::endl;
	}
};

int main(int argc, char **argv)
{
	Cat ticky("ticky");
	Dog spotty("spotty");
	// ticky and spotty can both speak...
	// ... but each of them in their own language.
	ticky.speak();
	spotty.speak();
}
