#pragma once

#include "Visitor.h"

class CountingVisitor : public Visitor
{
	int numberOfCircles;
	int numberOfRectangles;
	int numberOfComposites;


public:
	CountingVisitor()
		: numberOfCircles(0), numberOfRectangles(0), numberOfComposites(0)
	{
	}

	virtual void VisitCircle(Circle &circle)
	{
		numberOfCircles++;
	}

	virtual void VisitRectangle(Rectangle &rectangle)
	{
		numberOfRectangles++;
	}

	virtual void VisitComposite(CompositeShape &composite) 
	{
		numberOfComposites++;
	}
};