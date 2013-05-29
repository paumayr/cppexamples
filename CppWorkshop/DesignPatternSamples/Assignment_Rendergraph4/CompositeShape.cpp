#include "CompositeShape.hpp"

#include <iostream>
#include <algorithm>

void CompositeShape::addShape(ShapePtr shape)
{
	shapes.push_back(shape);
}

void CompositeShape::removeShape(ShapePtr shape)
{
	shapes.erase(std::remove(shapes.begin(), shapes.end(), shape), shapes.end());
}

// calls the shape visitor
void CompositeShape::accept(ShapeVisitor &visitor)
{
	visitor.beginComposite(*this);

	for(ShapeContainer::const_iterator it = shapes.begin(); it != shapes.end(); ++it)
	{
		(*it)->accept(visitor);
	}

	visitor.endComposite(*this);
}

// calculates the sum of the are of all shapes
// not concerned about overlap
double CompositeShape::calculateArea() const
{
	double sumOfAllAreas = 0.0;
	for (ShapeContainer::const_iterator it = shapes.begin(); it != shapes.end(); ++it)
	{
		sumOfAllAreas += (*it)->calculateArea();
	}

	return sumOfAllAreas;
}