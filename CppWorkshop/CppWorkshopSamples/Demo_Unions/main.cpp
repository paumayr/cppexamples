#include <iostream>

struct AnUnion
{
	int integer;
	float real; 
};

struct Variant
{
	int type;
	AnUnion value;
};

enum VariantTypes
{
	Float = 10,
	Integer
};

int main(int argc, char **argv)
{
	AnUnion u;
	u.integer = 10;
	std::cout << "u.integer: " << u.integer << " u.real: " << u.real << std::endl;

	u.real = 12.5;
	std::cout << "u.integer: " << u.integer << " u.real: " << u.real << std::endl;

	Variant x;

	x.type = VariantTypes::Float;
	x.type = Integer;

	return 0;
}