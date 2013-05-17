#include <iostream>

class Base
{
public:
	Base()
	{
	}

	Base(Base &other)
	{
	}
public:
	virtual void printInfo()
	{
			std::cout << "BaseClass" << std::endl;
	}
};


class Derived : public Base
{
public:
	virtual void printInfo()
	{
		std::cout << "DerivedClass" << std::endl;
	}
};



void print(Base instance)
{
	instance.printInfo();
}


int main()
{
	Derived d;
}