#include "SnowmanHouseBuilder.hpp"

#include "ShapeFactory.hpp"

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "CompositeShape.hpp"

using namespace std;

shared_ptr<Shape> SnowmanHouseBuilder::LoadShape(shared_ptr<ShapeFactory> shapeFactory)
{
	typedef shared_ptr<Circle> CirclePtr;
	typedef shared_ptr<Rectangle> RectanglePtr;
	typedef shared_ptr<CompositeShape> CompositeShapePtr;

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

	return scene;
}