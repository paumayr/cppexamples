#include <iostream>

class Base
{
public:
	Base() { std::cout << "base constructor" << std::endl; }
  virtual ~Base() { std::cout << "base destructor" << std::endl; }
};

class Derived : public Base
{
public:
	Derived() { std::cout << "derived constructor" << std::endl; }
	virtual ~Derived() { std::cout << "dervied destructor" << std::endl; }
};

class Derived2 : public Derived
{
public:
	Derived2() { std::cout << "derived2 constructor" << std::endl; }
	virtual ~Derived2() { std::cout << "dervied2 destructor" << std::endl; }
};

int main(int argc, char **argv)
{

	Base *pointerBase = new Derived2();

	delete pointerBase;
}