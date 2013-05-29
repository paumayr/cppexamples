#pragma once

#include <memory>
#include <vector>

#include "CarPart.hpp"
#include "Wheel.hpp"
#include "Body.hpp"
#include "Engine.hpp"

class Car : public CarPart
{
public:
	Car();
	virtual void accept(CarPartVisitor &visitor);

private:

	typedef std::shared_ptr<Wheel> WheelPtr;
	std::vector<WheelPtr> wheels;

	Engine engine;
	Body body;
};