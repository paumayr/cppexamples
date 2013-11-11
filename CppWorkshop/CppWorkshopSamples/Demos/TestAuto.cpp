#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int other()
{
	return 42;
}

template<typename U, typename V>
auto my_func(U a, V b) 
	-> decltype(a + b) // not evaluated, only for type-deduction
{
	return a + b;
}

void sample()
{
	const double x = 10.0;
	const auto x1 = x;
}


void foreach()
{
	vector<int> v{ 10, 20, 30 };

	for (auto &x : v)
	{
		cout << "x*x = " << x;
	}

	for (vector<int>::iterator it = v.begin();
		it != v.end();
		++it)
	{
		int &x = (*it);
		cout << "x*x = " << x;
	}
}

class MyClass
{
public:
	MyClass() {};
};

void some_func()
{
	initializer_list<int> x { 1, 2, 3, 4, 5 };
	MyClass a{};
}

template<typename T>
void some_init_func(initializer_list<T> xs)
{
	for (auto &x : xs)
	{
		cout << x;
	}
}


void test_some_init()
{
}

