#pragma once

#include "Shape.hpp"
#include "vector2.hpp"

class Circle : public Shape
{
	vector2f center;
	float radius;
public:
	Circle(const vector2f& _center, float _radius);

	const vector2f& getCenter() const;
	void setCenter(const vector2f &newCenter);

	float getRadius() const;
	void setRadius(float newRadius);
	
	virtual void accept(ShapeVisitor &visitor);

	// calculates the area of the shape
	virtual double calculateArea() const;
};