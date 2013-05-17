
#include <iostream>
#include <string>

class Pet
{
	std::string name;
public:
	Pet(const std::string &_name) : name(_name)	{ }
	~Pet() { std::cout << "ahhhhhhh" << std::endl; }

	virtual void speak() {
		std::cout << "I am " + name + " and can talk" << std::endl;
	}

	const std::string & getName()
	{
		return name;
	}
};

class Cat : public Pet
{
public:
	Cat(const std::string& name) : Pet(name) {}
	~Cat() { }
	void purr() {
		std::cout << "purrrrrrrrr" << std::endl;
	}

	virtual void speak() {
		Pet::speak();
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

void letPetSpeak(Pet& pet)
{
	std::cout << pet.getName() + " says: ";
	pet.speak();
}


int main(int argc, char **argv)
{
	Cat ticky("ticky");
	Dog spotty("spotty");
	
	letPetSpeak(ticky);
	letPetSpeak(spotty);
}
