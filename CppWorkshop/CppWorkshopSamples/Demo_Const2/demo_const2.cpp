#include <string>
#include <iostream>

class Person
{
	std::string firstName;
	std::string lastName;

public:
	
	const std::string &getFirstName() const
	{
		return firstName;
	}

	const std::string &getLastName() const 
	{
		return lastName;
	}

	std::string setLastName(std::string newLastName)
	{
		lastName = newLastName;
	}

};

void somefunc(int& a)
{
	a = 10;
}

void print(const Person &person)
{
	std::string lastName = person.getLastName();
	
	std::cout << person.getFirstName() << ", " << person.getLastName() << std::endl;
}

int main(int argc, char **argv)
{
	int outer = 5;

	somefunc(outer);
}