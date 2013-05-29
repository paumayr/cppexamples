#include <iostream>
#include <string>

using namespace std;

class CopyCat
{
public:
	string name;
	CopyCat(string _name) : name(_name)	{}

	// copy constructor
	CopyCat(CopyCat& other) : name("copy of " + other.name) {}
};


void copycatfunc(CopyCat &somecopycat)
{
	std::cout << somecopycat.name << std::endl;
}

int main(int argc, char **argv)
{
	CopyCat a ("ticky");

	copycatfunc(a);

	// copy constructor
	CopyCat b (a);
	// copy constructor
	CopyCat c = b;

	CopyCat d("d");

	d = a;

	std::cout << "name of a: " << a.name << std::endl;
	std::cout << "name of b: " << b.name << std::endl;
	std::cout << "name of c: " << c.name << std::endl;
	
	std::cout << "name of d: " << d.name << std::endl;
}