#pragma once

#include "Shape.hpp"
#include "vector2.hpp"

class Rectangle : public Shape
{
	vector2f point;
	double width;
	double height;
public:
	Rectangle(vector2f _point, double _width, double _height);

	const vector2f& getPoint() const;
	void setPoint(const vector2f& newPoint);

	double getWidth() const;
	void setWidth(double newWidth);

	double getHeight() const;
	void setHeight(double newHeight);

	// renders the shape (create output at least)...
	virtual void render() const;

	// calculates the area of the shape
	virtual double calculateArea() const;

	virtual void accept(Visitor &visitor) override;
};