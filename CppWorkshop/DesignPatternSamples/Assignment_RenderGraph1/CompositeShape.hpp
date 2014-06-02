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
	// OR std::vector<std::shared_ptr<Shape> > shapes2;

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

	// accepts a visitor.
	virtual void accept(Visitor& visitor) override;
};