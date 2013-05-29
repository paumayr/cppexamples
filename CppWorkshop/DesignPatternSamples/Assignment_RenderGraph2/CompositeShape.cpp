#include <iostream>
#include <algorithm>

#include "CompositeShape.hpp"

void CompositeShape::AddShape(ShapePtr shape)
{
	shapes.push_back(shape);
}

void CompositeShape::RemoveShape(ShapePtr shape)
{
	shapes.erase(std::remove(shapes.begin(), shapes.end(), shape), shapes.end());
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


void CompositeShape::accept(ShapeVisitor &visitor)
{
	visitor.beginComposite(*this);

	// C++ 11 style for each loop
	for(ShapePtr &it : this->shapes)
	{
		it->accept(visitor);
	}

	visitor.endComposite(*this);
}