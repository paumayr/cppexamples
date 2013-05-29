#pragma once
#pragma once

#include "CarPartVisitor.hpp"

class CarPartPrintVisitor : public CarPartVisitor
{
public:
	virtual void accept(Body &body);
	virtual void accept(Wheel &wheel);
	virtual void accept(Engine &engine);
	virtual void accept(Car &car);
};