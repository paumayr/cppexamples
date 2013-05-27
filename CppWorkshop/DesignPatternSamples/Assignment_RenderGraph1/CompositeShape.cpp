

#include "CompositeShape.hpp"
#include "Visitor.h"


void CompositeShape::AddShape(ShapePtr shape)
{
	this->shapes.push_back(shape);
}

// renders the shape (create output at least)...
void CompositeShape::render() const
{
	for (int i = 0; i < this->shapes.size(); i++)
	{
		this->shapes[i]->render();
	}
}

// calculates the sum of the are of all shapes
// not concerned about overlap
double CompositeShape::calculateArea() const
{
	double sum = 0.0;
	for (int i = 0; i < this->shapes.size(); i++)
	{
		sum += this->shapes[i]->calculateArea();
	}

	return sum;
}

void CompositeShape::visit(Visitor& visitor)
{
	visitor.VisitComposite(*this);

	for(int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->visit(visitor);
	}
}