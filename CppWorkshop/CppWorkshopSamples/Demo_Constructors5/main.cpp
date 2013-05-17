#include <iostream>
class BadConstructorList
{
public:
	int a, b, c;
	BadConstructorList(int i)
		: c(i++), 
		b(i++), 
		a(i++)
	{}
};

int main(int argc, char **argv)
{
	BadConstructorList x(1);
	std::cout << "a = " << x.a << " b = " << x.b << " c = " << x.c << std::endl;
	return 0;
}