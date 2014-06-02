
#include "CompositeShape.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "RenderShapeVisitor.hpp"

#include <iostream>
#include <memory>
#include <string>

#include "StandardShapeFactory.hpp"
#include "DebugShapeFactory.hpp"

#include "SnowmanHouseBuilder.hpp"
#include "InteractiveShapeBuilder.hpp"

using namespace std;

shared_ptr<ShapeFactory> createShapeFactory(const std::string& type)
{
	if (type == "standard")
	{
		return shared_ptr<ShapeFactory>(new StandardShapeFactory());
	}
	else if (type == "debug")
	{
		return shared_ptr<ShapeFactory>(new DebugShapeFactory());
	}

	throw new std::exception("could not find factory");
}

shared_ptr<ShapeBuilder> createShapeBuilder(const std::string& type)
{
	if (type == "snowmanhousebuilder")
	{
		return shared_ptr<ShapeBuilder>(new SnowmanHouseBuilder());
	} 
	else if (type == "interactive")
	{
		return shared_ptr<ShapeBuilder>(new InteractiveShapeBuilder());
	}

	throw new std::exception("could not find builder");
}


int main(int argc, char ** argv)
{
	shared_ptr<ShapeFactory> shapeFactory = createShapeFactory("standard");
	shared_ptr<ShapeBuilder> shapeBuilder = createShapeBuilder("interactive");
	
	shared_ptr<Shape> scene = shapeBuilder->LoadShape(shapeFactory);

	std::cout << "the scene has an area of " << scene->calculateArea() << " square units" << std::endl;
	
	RenderShapeVisitor renderer;
	scene->accept(renderer);

	return 0;
}