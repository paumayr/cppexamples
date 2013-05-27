#pragma once

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "CompositeShape.hpp"

class Visitor
{
public:
	virtual void VisitCircle(Circle &circle) = 0;

	virtual void VisitRectangle(Rectangle &rectangle) = 0;

	virtual void VisitComposite(CompositeShape &composite) = 0;
};