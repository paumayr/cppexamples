
#pragma once

#include "Visitor.h"

class CountVisitor : public Visitor
{
public:
	int circleCount;
	int rectangleCount;
	int compositCount;

	virtual void visitCircle(Circle &circle) override
	{
		this->circleCount++;
	}

	// Called when a rectangle is visited.
	virtual void visitRectangle(Rectangle &rectangle) override
	{
		this->rectangleCount++;
	}

	// called when a composite shape is visited.
	virtual void visitComposite(CompositeShape &composite) override
	{
		this->compositCount++;
	}
};