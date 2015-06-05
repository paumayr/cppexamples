#include "stdafx.h"
#include <iostream>

TEST_CLASS(TestSlicing)
{
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


	TEST_METHOD(TestSlicingMain)
	{
		Derived d;
		// D is copied into instance parameter of print method of type Base -> no Derived instance any more.
		print(d);
	}
};