#pragma once

#include "Shape.hpp"
#include <memory>
#include <vector>

class CompositeShape : public Shape
{
	typedef std::tr1::shared_ptr<Shape> ShapePtr;
	typedef std::vector<ShapePtr> ShapeContainer;

	ShapeContainer shapes;
public:
	void AddShape(ShapePtr shape);
	void RemoveShape(ShapePtr shape);

	virtual void accept(ShapeVisitor &visitor);

	// calculates the sum of the are of all shapes
	// not concerned about overlap
	virtual double calculateArea() const;
};