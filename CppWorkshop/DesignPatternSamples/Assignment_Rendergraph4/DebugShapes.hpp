#pragma once

#include <iostream>

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "CompositeShape.hpp"


// This class contains alternate implementations for all shapes
// they output debug information befor and after accepting a visitor.
// used for demonstration purposed of shape factory.
class DebugCircle : public Circle
{
public:
	DebugCircle(const vector2f& _center, float _radius)
		: Circle(_center, _radius)
	{
	}

	virtual void accept(ShapeVisitor &visitor)
	{
		std::cout << "before Circle::accept" << std::endl;
		Circle::accept(visitor);
		std::cout << "after Circle::accept" << std::endl;
	}
};

class DebugRectangle : public Rectangle
{
public:
	DebugRectangle(vector2f _point, double _width, double _height)
		: Rectangle(_point, _width, _height)
	{
	}

	virtual void accept(ShapeVisitor &visitor)
	{
		std::cout << "before Rectangle::accept" << std::endl;
		Rectangle::accept(visitor);
		std::cout << "before Rectangle::accept" << std::endl;
	}
};


class DebugCompositeShape : public CompositeShape
{
public:
	void accept(ShapeVisitor &visitor)
	{
		std::cout << "before CompositeShape::accept" << std::endl;
		CompositeShape::accept(visitor);
		std::cout << "after CompositeShape::accept" << std::endl;
	}
};