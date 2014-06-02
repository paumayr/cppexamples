#pragma once

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "CompositeShape.hpp"

class Visitor
{
public:
	// Called when a circle is visited.
	virtual void visitCircle(Circle &circle) = 0;

	// Called when a rectangle is visited.
	virtual void visitRectangle(Rectangle &rectangle) = 0;

	// called when a composite shape is visited.
	virtual void visitComposite(CompositeShape &composite) = 0;
};