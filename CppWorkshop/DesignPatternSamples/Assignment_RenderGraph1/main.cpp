
#include "CompositeShape.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "CountVisitor.hpp"

#include <iostream>
#include <memory>

using namespace std;


shared_ptr<Shape> CreateScene()
{
	
	typedef shared_ptr<Circle> CirclePtr;
	typedef shared_ptr<Rectangle> RectanglePtr;
	typedef shared_ptr<CompositeShape> CompositeShapePtr;

	CompositeShapePtr snowman (new CompositeShape());

	RectanglePtr leftFoot (new Rectangle(vector2f(5.0f, 1.0f), 1.0f, 1.0f));
	RectanglePtr rightFoot (new Rectangle(vector2f(3.0f, 1.0f), 1.0f, 1.0f));

	CirclePtr body (new Circle(vector2f(4.0f, 4.0f), 3.5f));
	CirclePtr head (new Circle(vector2f(4.0f, 7.0f), 2.0f));

	snowman->AddShape(leftFoot);
	snowman->AddShape(rightFoot);

	snowman->AddShape(body);
	snowman->AddShape(head);

	CompositeShapePtr house (new CompositeShape());

	RectanglePtr wall (new Rectangle(vector2f(-5.0f, 10.0f), 7.0f, 10.0f));
	RectanglePtr door (new Rectangle(vector2f(-4.5f, 7.0f), 3.0f, 7.0f));
	RectanglePtr window (new Rectangle(vector2f(-0.5f, 6.5f), 2.0f, 2.0f));

	house->AddShape(wall);
	house->AddShape(door);
	house->AddShape(window);

	CompositeShapePtr scene (new CompositeShape());

	scene->AddShape(snowman);
	scene->AddShape(house);

	return scene;
}

int main(int argc, char ** argv)
{	
	std::shared_ptr<Shape> scene = CreateScene();

	std::cout << "the scene has an area of " << scene->calculateArea() << " square units" << std::endl;
	scene->render();

	CountVisitor counter;

	scene->accept(counter);

	return 0;
}