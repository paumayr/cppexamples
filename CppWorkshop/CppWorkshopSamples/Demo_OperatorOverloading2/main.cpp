#include <iostream>

class Fraction
{
public:
	int above;
	int below;

	Fraction(int _above, int _below) : above(_above), below(_below) {}

	void operator+= (Fraction rh) {
		above = above * rh.below + rh.above * below;
		below = below * rh.below;
	}

	void operator-= (Fraction rh) {
		above = above * rh.below - rh.above * below;
		below = below * rh.below;
	}

	void operator*= (Fraction rh) {
		above = above * rh.above;
		below = below * rh.below;
	}

	void operator/= (Fraction rh) {
		above = above * rh.below;
		below = below * rh.above;
	}
};

std::ostream& operator<<(std::ostream& out, Fraction x)
{
	out << "(" << x.above << "/" << x.below << ")";
	return out;
}

int main(int argc, char **argv)
{
	Fraction a(4, 2);
	Fraction b(6, 3);

	std::cout << "before: " << a << std::endl;
	a += Fraction(1, 2);
	std::cout << "after add: " << a << std::endl;
	a -= Fraction(1, 2);
	std::cout << "after subtract: " << a << std::endl;
	a *= Fraction(2, 1);
	std::cout << "after mul: " << a << std::endl;
	a /= Fraction(2, 1);
	std::cout << "after div: " << a << std::endl;
}