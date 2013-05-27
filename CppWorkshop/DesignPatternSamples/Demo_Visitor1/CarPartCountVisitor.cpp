#include "CarPartCountVisitor.hpp"

#include <iostream>


CarPartCountVisitor::CarPartCountVisitor()
:
wheelCount(0),
bodyCount(0),
engineCount(0),
carCount(0)
{
}

void CarPartCountVisitor::accept(Body &body)
{
	bodyCount++;
}

void CarPartCountVisitor::accept(Wheel &wheel)
{
	wheelCount++;
}

void CarPartCountVisitor::accept(Engine &engine)
{
	engineCount++;
}

void CarPartCountVisitor::accept(Car &car)
{
	carCount++;
}

void CarPartCountVisitor::printSummary() const
{
	std::cout << "I visited" << std::endl;
	std::cout << "\t" << wheelCount << " wheels" << std::endl;
	std::cout << "\t" << bodyCount << " car bodies" << std::endl;
	std::cout << "\t" << engineCount << " engines" << std::endl;
	std::cout << "\t" << carCount << " cars" << std::endl;
}
