#pragma once

#include "CarPartVisitor.hpp"

class CarPartCountVisitor : public CarPartVisitor
{
	int wheelCount;
	int bodyCount;
	int engineCount;
	int carCount;
public:
	CarPartCountVisitor();

	virtual void accept(Body &body);
	virtual void accept(Wheel &wheel);
	virtual void accept(Engine &engine);
	virtual void accept(Car &car);

	void printSummary() const;
};
