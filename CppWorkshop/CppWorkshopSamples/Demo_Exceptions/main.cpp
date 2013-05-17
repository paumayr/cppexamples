#include <exception>
#include <iostream>
#include <cmath>

struct square_root_exception : public std::exception
{
public:
};

class StackMonitor
{
public:
	~StackMonitor()
	{
		std::cout << "Destructing" << std::endl;
	}
};

float squareRoot(float f)
{
	if (f < 0.0f)
	{
		throw square_root_exception();
	}

	return sqrtf(f);
}

void readFile(int *data, std::string filename)
{
	// throw std::exception("reading file failed");
}

void ComplexCalculation()
{
	int * daten = new int[1000];

	StackMonitor sm;

	readFile(daten, "filename");

	squareRoot(100.0f);

	throw int(10);

	delete[] daten;
}

int main(int argc, char **argv)
{
	try
	{
		ComplexCalculation();
		std::cout << "this line will never be printed" << std::endl;
	}
	catch(square_root_exception &sqex)
	{
		std::cout << "negate square root!??!" << std::endl;
	}
	catch(std::exception &ex)
	{
		std::cout << "caught exception " << ex.what() << std::endl;
	}
	catch(...)
	{
		std::cout << "something else happened" << std::endl;
	}
	
	std::cin.get();
	return 0;
}
