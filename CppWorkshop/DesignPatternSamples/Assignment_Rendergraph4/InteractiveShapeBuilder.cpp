
#include "InteractiveShapeBuilder.hpp"
#include "ShapeFactory.hpp"

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "CompositeShape.hpp"

#include <string>
#include <iostream>

using namespace std;
using namespace std::tr1;

shared_ptr<Shape> InteractiveShapeBuilder::LoadShape(shared_ptr<ShapeFactory> factory)
{
	return createShape(factory, 0);

}
shared_ptr<Shape> InteractiveShapeBuilder::createShape(shared_ptr<ShapeFactory> factory, int level)
{
	printMenu(level);

	switch(getMenuChoise())
	{
	case Circle:
		return createCircle(factory, level + 1);
		break;
	case Rectangle:
		return createRectangle(factory, level + 1);
		break;
	case Composite:
		return createComposite(factory, level + 1);
		break;
	}

	return 0;
}

shared_ptr<Shape> InteractiveShapeBuilder::createCircle(std::tr1::shared_ptr<ShapeFactory> factory, int level)
{
	// TODO add better error checking here.
	printIndent(level);
	float x, y, r;
	cout << "x z r: ";
	cin >> x >> y >> r;

	return shared_ptr<Shape>(factory->CreateCircle(vector2f(x, y), r));
}

shared_ptr<Shape> InteractiveShapeBuilder::createRectangle(std::tr1::shared_ptr<ShapeFactory> factory, int level)
{
	printIndent(level);
	float x, y, w, h;
	cout << "x z w h: ";
	cin >> x >> y >> w >> h;

	return shared_ptr<Shape>(factory->CreateRectangle(vector2f(x, y), w, h));
}

shared_ptr<Shape> InteractiveShapeBuilder::createComposite(std::tr1::shared_ptr<ShapeFactory> factory, int level)
{
	bool keepAdding = true;

	shared_ptr<CompositeShape> composite = factory->CreateComposite();
	while(keepAdding)
	{
		printMenu(level);

		switch(getMenuChoise())
		{
		case Circle:
			composite->addShape(createCircle(factory, level + 1));
			break;
		case Rectangle:
			composite->addShape(createRectangle(factory, level + 1));
			break;
		case Composite:
			composite->addShape(createComposite(factory, level + 1));
			break;
		case Done:
			keepAdding = false;
		}
	}

	return composite;
}

void InteractiveShapeBuilder::printMenu(int level) const
{
	printIndent(level);
	cout << "menu: press..." << std::endl;
	printIndent(level + 1);
	cout << Circle << ") for a new circle" << std::endl;

	printIndent(level + 1);
	cout << Rectangle << ") for a new rectangle" << std::endl;

	printIndent(level + 1);
	cout << Composite << ") for a new composite" << std::endl;

	printIndent(level + 1);
	cout << Done << ") for done" << std::endl;
}

void InteractiveShapeBuilder::printIndent(int level) const
{
	string space(level, ' ');
	cout << space;
}

InteractiveShapeBuilder::MenuChoice InteractiveShapeBuilder::getMenuChoise()
{
	int answer;

	while(true)
	{
		cin >> answer;

		if (!cin.fail())
		{
			if (answer > FirstChoice && answer < LastChoice)
			{
				return (MenuChoice)answer;
			}
		}
		
		std::cout << "Please enter a value between " << FirstChoice << " and " << LastChoice << std::endl;
	}
}
