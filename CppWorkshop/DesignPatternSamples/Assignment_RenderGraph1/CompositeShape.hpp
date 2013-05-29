#pragma once

#include <memory>
#include <vector>

#include "Shape.hpp"

class Visitor;

typedef std::shared_ptr<Shape> ShapePtr;
typedef std::vector<ShapePtr> ShapeContainer;

class CompositeShape : public Shape
{
	ShapeContainer shapes;
public:
	void AddShape(ShapePtr shape);

	int numberOfShapes()
	{
		return shapes.size();
	}

	// renders the shape (create output at least)...
	virtual void render() const;

	// calculates the sum of the are of all shapes
	// not concerned about overlap
	virtual double calculateArea() const;





	virtual void visit(Visitor& visitor);

	virtual void count(Counter &counter)
	{
		counter.composites++;
		for(int i = 0; i < shapes.size(); i++)
		{
			shapes[i]->count(counter);
		}
	}
};