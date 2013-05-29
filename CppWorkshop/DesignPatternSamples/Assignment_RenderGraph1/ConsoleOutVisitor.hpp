#pragma once 
#include <iostream>
#include "Visitor.h"

class ConsoleOutVisitor : public Visitor
{
public:
	virtual void VisitCircle(Circle &circle)
	{
		std::cout << "Circle(" << circle.getCenter().x << "/" << circle.getCenter().y << ", " << circle.getRadius() << ")" << std::endl;
	}

	virtual void VisitRectangle(Rectangle &rectangle)
	{
		std::cout << "Rectangle(" << rectangle.getPoint().x << "/" << rectangle.getPoint().y << ", ";
		std::cout << rectangle.getWidth() << " / " << rectangle.getHeight() << ")" << std::endl;
	}

	virtual void VisitComposite(CompositeShape &composite)
	{
		std::cout << "Composite(" << composite.numberOfShapes() << ")" << std::endl;
	}
};
