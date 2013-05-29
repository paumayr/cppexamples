
#include "Car.hpp"
#include "CarPartPrintVisitor.hpp"
#include "CarPartCountVisitor.hpp"


int main(int argc, char **argv)
{
	Car car1;
	
	CarPartPrintVisitor printVisitor;
	car1.accept(printVisitor);

	CarPartCountVisitor countVisitor;
	car1.accept(countVisitor);

	// visit another car with the same visitor
	Car car2;
	car2.accept(countVisitor);

	countVisitor.printSummary();

	return 0;
}