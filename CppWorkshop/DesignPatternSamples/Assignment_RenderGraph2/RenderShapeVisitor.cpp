
#include "RenderShapeVisitor.hpp"

#include "Rectangle.hpp"
#include "Circle.hpp"
#include "CompositeShape.hpp"
#include "vector2.hpp" 
#include "vector2extra.hpp"

#include <string>
#include <iostream>

RenderShapeVisitor::RenderShapeVisitor()
: indentLevel(0)
{
}

void RenderShapeVisitor::beginComposite(CompositeShape &shape)
{
	printIndent();
	std::cout << "start composite shape" << std::endl;
	indentLevel++;
}

void RenderShapeVisitor::visit(Rectangle &rectangle)
{
	printIndent();
	std::cout << "rectangle at " << rectangle.getPoint() 
			<< " with: " << rectangle.getWidth()
			<< " height: " << rectangle.getHeight()
			<< std::endl;
}

void RenderShapeVisitor::visit(Circle &circle)
{
	printIndent();
	std::cout << "circle at " << circle.getCenter()
			<< " radius: " << circle.getRadius()
			<< std::endl;
}

void RenderShapeVisitor::endComposite(CompositeShape &shape)
{
	indentLevel--;
	printIndent();
	std::cout << "end composite shape" << std::endl;
}

void RenderShapeVisitor::printIndent()
{
	std::string indent(2 * indentLevel, ' ');
	std::cout << indent;
}