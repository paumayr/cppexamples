#pragma once

#include "ShapeBuilder.hpp"


class InteractiveShapeBuilder : public ShapeBuilder
{
	enum MenuChoice {
		FirstChoice = 0,
		Circle,
		Rectangle,
		Composite,
		Done,
		LastChoice
	};
public:
	virtual std::tr1::shared_ptr<Shape> LoadShape(std::tr1::shared_ptr<ShapeFactory> factory);

private:
	std::tr1::shared_ptr<Shape> createShape(std::tr1::shared_ptr<ShapeFactory> factory, int level);
	void printMenu(int level) const;
	void printIndent(int level) const;

	std::tr1::shared_ptr<Shape> createCircle(std::tr1::shared_ptr<ShapeFactory> factory, int level);
	std::tr1::shared_ptr<Shape> createRectangle(std::tr1::shared_ptr<ShapeFactory> factory, int level);
	std::tr1::shared_ptr<Shape> createComposite(std::tr1::shared_ptr<ShapeFactory> factory, int level);


	MenuChoice getMenuChoise();

};