
#include <iostream>
#include "CarPartPrintVisitor.hpp"

#include "Wheel.hpp"

void CarPartPrintVisitor::accept(Body &body)
{
	std::cout << "visiting body" << std::endl;
}

void CarPartPrintVisitor::accept(Wheel &wheel)
{
	std::cout << "visiting " << wheel.getName() << " wheel." << std::endl;
}

void CarPartPrintVisitor::accept(Engine &engine)
{
	std::cout << "visiting engine" << std::endl;
}

void CarPartPrintVisitor::accept(Car &car)
{
	std::cout << "visiting car" << std::endl;
}