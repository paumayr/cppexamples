
#include "Car.hpp"

Car::Car()
{
	wheels.push_back(WheelPtr(new Wheel("front left")));
	wheels.push_back(WheelPtr(new Wheel("front right")));
	wheels.push_back(WheelPtr(new Wheel("back left")));
	wheels.push_back(WheelPtr(new Wheel("back right")));
}

void Car::accept(CarPartVisitor &visitor)
{
	// NOTE: use auto in C++11
	typedef std::vector<WheelPtr> WheelVector;
	for(WheelVector::iterator it = wheels.begin(); it != wheels.end(); ++it)
	{
		WheelPtr w = *it;
		visitor.accept(*w);
	}

	visitor.accept(engine);
	visitor.accept(body);
	visitor.accept(*this);
}