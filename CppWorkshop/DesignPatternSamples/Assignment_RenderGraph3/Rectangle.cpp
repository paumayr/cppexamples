#include "Rectangle.hpp"

#include "ShapeVisitor.hpp"

Rectangle::Rectangle(vector2f _point, double _width, double _height)
	: point(_point), width(_width), height(_height)
{
}

const vector2f& Rectangle::getPoint() const
{
	return point;
}

void Rectangle::setPoint(const vector2f& newPoint)
{
	point = newPoint;
}

double Rectangle::getWidth() const	
{
	return width;
}

void Rectangle::setWidth(double newWidth)
{
	width = newWidth;
}

double Rectangle::getHeight() const
{
	return height;
}

void Rectangle::setHeight(double newHeight)
{
	height = newHeight;
}

// accepts a shape visitor, calling its OnRectangle function
void Rectangle::accept(ShapeVisitor &visitor)
{
	visitor.visit(*this);
}

// calculates the area of the shape
double Rectangle::calculateArea() const
{
	return width * height;
}