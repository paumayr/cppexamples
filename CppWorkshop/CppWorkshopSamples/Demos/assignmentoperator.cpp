#include "stdafx.h"
#include <iostream>
#include <string>


TEST_CLASS(TestAssignmentOperator)
{
	class SomeClass
	{
		std::string name;
	public:
		SomeClass(const std::string &n) : name(n) {}
		SomeClass(const SomeClass& other) {
			name = "copy of " + other.name;
		}
		const SomeClass& operator=(const SomeClass &other) {
			if (this != &other)
			{
				name = "assigned from " + other.name;
			}

			return *this;
		}

		const std::string& getName() const {
			return name;
		}
	};

public:
	TEST_METHOD(TestAssignmentOperatorMain)
	{
		SomeClass sc("original");
		SomeClass x("x");

		std::cout << "sc name = " << sc.getName() << std::endl;
		std::cout << "x name = " << x.getName() << std::endl;
		x = sc;
		std::cout << "x name = " << x.getName() << std::endl;

		SomeClass a("a");
		SomeClass b("b");
		SomeClass c("c");

		a = b = c;

		std::cout << "a.getName() = " << a.getName() << std::endl;
		std::cout << "b.getName() = " << b.getName() << std::endl;
		std::cout << "c.getName() = " << c.getName() << std::endl;

		std::cout << "b.getName() = " << b.getName() << std::endl;

		b = b;
		std::cout << "b.getName() = " << b.getName() << std::endl;
	}
};
