#include <iostream>
#include <string>
#include "Rectangle.hpp"
#include "vector2.hpp"

#include "Visitor.h"

Rectangle::Rectangle(vector2f _point, double _width, double _height)
	: point(_point), width(_width), height(_height)
{
}


const vector2f& Rectangle::getPoint() const
{
	return this->point;
}

void Rectangle::setPoint(const vector2f& newPoint)
{
	this->point = newPoint;
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

// renders the shape (create output at least)...
void Rectangle::render() const
{
	std::cout << "rendering a rectangle at (" << point.x << " / " << point.y << ") with: " << width << " height: " << height;
}

// calculates the area of the shape
double Rectangle::calculateArea() const
{
	return width * height;
}

void Rectangle::visit(Visitor &visitor)
{
	visitor.VisitRectangle(*this);
}
