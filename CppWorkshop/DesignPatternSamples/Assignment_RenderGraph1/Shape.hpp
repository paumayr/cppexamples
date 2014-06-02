#pragma once

class Visitor;

struct Counter
{
	int rectangles;
	int circles;
	int composites;
};

class Shape
{
public:
	Shape();
	virtual ~Shape();

	// renders the shape (create output at least)...
	virtual void render() const = 0;

	// calculates the area of the shape
	virtual double calculateArea() const = 0;

	// provides additional extensions
	virtual void accept(Visitor &visitor) = 0;
};