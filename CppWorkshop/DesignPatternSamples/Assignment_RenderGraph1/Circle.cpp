
#include <iostream>

#include "Circle.hpp"

#include "Math.hpp"
#include "vector2.hpp"
#include "Visitor.h"


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

// renders the shape (create output at least)...
void Circle::render() const
{
	std::cout << "Rendering circle with radius " << radius << " and center at " << center.x << " / " << center.y;
}

// calculates the area of the shape
double Circle::calculateArea() const
{
	return radius * radius * Math::pi;
}

void Circle::accept(Visitor &visitor)
{
	visitor.visitCircle(*this);
}