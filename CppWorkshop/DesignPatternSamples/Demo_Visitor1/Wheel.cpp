#include "Wheel.hpp"

Wheel::Wheel (std::string _name)
: name(_name)
{
}

const std::string& Wheel::getName() const
{
	return name;
}

void Wheel::accept(CarPartVisitor &visitor)
{
	visitor.accept(*this);
}