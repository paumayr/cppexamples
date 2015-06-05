#include "stdafx.h"
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

TEST_CLASS(TestDemoUnions)
{
	TEST_METHOD(TestDemoUnionsMain)
	{
		AnUnion u;
		u.real = 10.0;
		u.integer = 10;
		std::cout << "u.integer: " << u.integer << " u.real: " << u.real << std::endl;

		u.real = 12.5;
		std::cout << "u.integer: " << u.integer << " u.real: " << u.real << std::endl;

		Variant x;

		x.type = VariantTypes::Float;
		x.type = Integer;
	}
};