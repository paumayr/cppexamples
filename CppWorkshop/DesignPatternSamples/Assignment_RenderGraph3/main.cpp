
#include "CompositeShape.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "RenderShapeVisitor.hpp"

#include <iostream>
#include <memory>
#include <string>

#include "StandardShapeFactory.hpp"

using namespace std;

shared_ptr<ShapeFactory> createShapeFactory(const std::string& type)
{
	if (type == "standard")
	{
		return shared_ptr<ShapeFactory>(new StandardShapeFactory());
	}

	throw new std::exception("could not find factory");
}

int main(int argc, char ** argv)
{
	typedef shared_ptr<Circle> CirclePtr;
	typedef shared_ptr<Rectangle> RectanglePtr;
	typedef shared_ptr<CompositeShape> CompositeShapePtr;

	shared_ptr<ShapeFactory> shapeFactory = createShapeFactory("standard");

	CompositeShapePtr snowman =	shapeFactory->CreateComposite();
	RectanglePtr leftFoot = shapeFactory->CreateRectangle(vector2f(5.0f, 1.0f), 1.0f, 1.0f);
	RectanglePtr rightFoot = shapeFactory->CreateRectangle(vector2f(3.0f, 1.0f), 1.0f, 1.0f);

	CirclePtr body = shapeFactory->CreateCircle(vector2f(4.0f, 4.0f), 3.5f);
	CirclePtr head = shapeFactory->CreateCircle(vector2f(4.0f, 7.0f), 2.0f);

	snowman->addShape(leftFoot);
	snowman->addShape(rightFoot);

	snowman->addShape(body);
	snowman->addShape(head);

	CompositeShapePtr house = shapeFactory->CreateComposite();

	RectanglePtr wall = shapeFactory->CreateRectangle(vector2f(-5.0f, 10.0f), 7.0f, 10.0f);
	RectanglePtr door = shapeFactory->CreateRectangle(vector2f(-4.5f, 7.0f), 3.0f, 7.0f);
	RectanglePtr window = shapeFactory->CreateRectangle(vector2f(-0.5f, 6.5f), 2.0f, 2.0f);

	house->addShape(wall);
	house->addShape(door);
	house->addShape(window);

	CompositeShapePtr scene = shapeFactory->CreateComposite();

	scene->addShape(snowman);
	scene->addShape(house);

	std::cout << "the scene has an area of " << scene->calculateArea() << " square units" << std::endl;
	
	RenderShapeVisitor renderer;
	scene->accept(renderer);

	return 0;
}