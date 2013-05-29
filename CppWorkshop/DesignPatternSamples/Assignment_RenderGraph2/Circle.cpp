
#include "Circle.hpp"

#include "Math.hpp"
#include "vector2extra.hpp"
#include <iostream>

Circle::Circle(const vector2f& _center, float _radius)
	: center(_center),
	radius(_radius)
{
}

const vector2f& Circle::getCenter() const
{
	return center;
}

void Circle::setCenter(const vector2f &newCenter)
{
	center = newCenter;
}

float Circle::getRadius() const
{
	return radius;
}

void Circle::setRadius(float newRadius)
{
	radius = newRadius;
}

// accepts a shape visitor, calling its OnCircle function
void Circle::accept(ShapeVisitor &visitor)
{
	visitor.visit(*this);
}

// calculates the area of the shape
double Circle::calculateArea() const
{
	return radius * radius * Math::pi;
}