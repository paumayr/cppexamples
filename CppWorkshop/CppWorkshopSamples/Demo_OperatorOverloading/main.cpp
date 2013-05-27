#include <iostream>

class Fraction
{
public:
	int above;
	int below;

	Fraction(int _above, int _below) : above(_above), below(_below) {}
};

Fraction add(const Fraction& left, const Fraction& right)
{
	return Fraction(left.above * right.below + right.above * left.below, left.below * right.below);
}

Fraction operator+(Fraction lh, Fraction rh)
{
	return Fraction(lh.above * rh.below + rh.above * lh.below, lh.below * rh.below);
}

Fraction operator-(Fraction lh, Fraction rh)
{
	return Fraction(lh.above * rh.below - rh.above * lh.below, lh.below * rh.below);
}

Fraction operator*(Fraction lh, Fraction rh)
{
	return Fraction(lh.above * rh.above, lh.below * rh.below);
}

Fraction operator/(Fraction lh, Fraction rh)
{
	return Fraction(lh.above * rh.below, lh.below * rh.above); 
}

std::ostream& operator<<(std::ostream& out, Fraction x)
{
	out << "(" << x.above << "/" << x.below << ")";
	return out;
}

int main(int argc, char **argv)
{
	Fraction a(4, 2);
	Fraction b(6, 3);

	Fraction sum = add(a, b);
	Fraction add = a + b + a;
	Fraction sub = a - b;
	Fraction mul = a * b;
	Fraction div = a / b;

	std::cout << "add " << add << std::endl;
	std::cout << "sub " << sub << std::endl;
	std::cout << "mul " << mul << std::endl;
	std::cout << "div " << div << std::endl;
}