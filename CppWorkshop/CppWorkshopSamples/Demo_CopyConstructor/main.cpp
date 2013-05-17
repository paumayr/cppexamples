#include <iostream>
#include <string>

using namespace std;

class CopyCat
{
	string name;
public:
	CopyCat(string _name) : name(_name)	{}

	// copy constructor
	CopyCat(CopyCat& other) : name("copy of " + other.name) {}
	string& getName() { return name; }
};

int main(int argc, char **argv)
{
	CopyCat a ("ticky");

	// copy constructor
	CopyCat b (a);
	// copy constructor
	CopyCat c = b;

	CopyCat d("d");

	d = a;

	std::cout << "name of a: " << a.getName() << std::endl;
	std::cout << "name of b: " << b.getName() << std::endl;
	std::cout << "name of c: " << c.getName() << std::endl;
	
	std::cout << "name of d: " << d.getName() << std::endl;
}