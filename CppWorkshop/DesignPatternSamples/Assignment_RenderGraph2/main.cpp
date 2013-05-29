
#include "CompositeShape.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "RenderShapeVisitor.hpp"

#include <iostream>
#include <memory>

using namespace std;
using namespace std::tr1;
int main(int argc, char ** argv)
{
	typedef shared_ptr<Circle> CirclePtr;
	typedef shared_ptr<Rectangle> RectanglePtr;
	typedef shared_ptr<CompositeShape> CompositeShapePtr;

	CompositeShapePtr snowman =	CompositeShapePtr(new CompositeShape());
	RectanglePtr leftFoot = RectanglePtr(new Rectangle(vector2f(5.0f, 1.0f), 1.0f, 1.0f));
	RectanglePtr rightFoot = RectanglePtr(new Rectangle(vector2f(3.0f, 1.0f), 1.0f, 1.0f));

	CirclePtr body = CirclePtr(new Circle(vector2f(4.0f, 4.0f), 3.5f));
	CirclePtr head = CirclePtr(new Circle(vector2f(4.0f, 7.0f), 2.0f));

	snowman->AddShape(leftFoot);
	snowman->AddShape(rightFoot);

	snowman->AddShape(body);
	snowman->AddShape(head);

	CompositeShapePtr house = CompositeShapePtr(new CompositeShape());

	RectanglePtr wall = RectanglePtr(new Rectangle(vector2f(-5.0f, 10.0f), 7.0f, 10.0f));
	RectanglePtr door = RectanglePtr(new Rectangle(vector2f(-4.5f, 7.0f), 3.0f, 7.0f));
	RectanglePtr window = RectanglePtr(new Rectangle(vector2f(-0.5f, 6.5f), 2.0f, 2.0f));

	house->AddShape(wall);
	house->AddShape(door);
	house->AddShape(window);

	CompositeShapePtr scene = CompositeShapePtr(new CompositeShape());

	scene->AddShape(snowman);
	scene->AddShape(house);

	std::cout << "the scene has an area of " << scene->calculateArea() << " square units" << std::endl;
	
	RenderShapeVisitor renderer;
	scene->accept(renderer);

	return 0;
}