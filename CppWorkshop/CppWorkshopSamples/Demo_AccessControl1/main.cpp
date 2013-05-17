#include <iostream>

class SomeClass
{
public:
	SomeClass() : publicmember(10), privatemember(5) {};

	int publicmember;

private:
	int privatemember;

public:
	int sum() {
		// member function can access public and private
		return publicmember + privatemember;
	}
};

int main(int argc, char **argv)
{
	SomeClass b;
	std::cout << "public member: " << b.publicmember << std::endl;
	// error, cannot access private member
	//std::cout << "private member: " << b.privatemember << std::endl;

	// ok, sum is public
	std::cout << "sum : " << b.sum() << std::endl;
}