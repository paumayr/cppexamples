#pragma once

#include "ShapeVisitor.hpp"

class Shape
{
public:
	Shape();
	virtual ~Shape();

	// accepts a shape visitor, triggering the specific functions
	// depending on type.
	virtual void accept(ShapeVisitor &visitor) = 0;

	// calculates the area of the shape
	virtual double calculateArea() const = 0;
};