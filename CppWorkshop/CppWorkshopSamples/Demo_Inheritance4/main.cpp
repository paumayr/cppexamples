
#include <iostream>
#include <string>

class Pet
{
	std::string name;
public:
	Pet(const std::string &_name) : name(_name)	{ }
	
	virtual void speak() = 0;

	const std::string & getName() 
	{
		return name;
	}
};

class Cat : public Pet
{
public:
	Cat(const std::string& name) : Pet(name) {}
	
	virtual void speak() {
		std::cout << "meeeeaaauuwww" << std::endl;
	}
};

class Dog : public Pet
{
public:
	Dog(const std::string& name) : Pet(name) {}
	
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

	// ERROR, cannot instantiate abstract class
	//Pet somePet;
}
