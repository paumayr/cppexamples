#include <string>
#include <iostream>
#include <memory>
#include <sstream>

int main(int argc, char **argv)
{
	std::string message = "Hello Kapsch";
	std::string exclamation = "!";

	std::string fullmessage = message + exclamation;

	int var1 = 20;
	double var2 = 22.2;

	std::stringstream combined;
	combined << message << var1 << var2;
	
	std::string msg = combined.str();
}
