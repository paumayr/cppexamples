
#pragma once

// forward declare shapes.
class CompositeShape;
class Rectangle;
class Circle;

class ShapeVisitor
{
public:
	virtual void beginComposite(CompositeShape &shape) = 0;

	virtual void visit(Rectangle &rectangle) = 0;
	virtual void visit(Circle &circle) = 0;

	virtual void endComposite(CompositeShape &shape) = 0;
};