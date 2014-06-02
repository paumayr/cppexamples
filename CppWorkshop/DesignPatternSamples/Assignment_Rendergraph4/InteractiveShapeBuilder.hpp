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
	virtual std::shared_ptr<Shape> LoadShape(std::shared_ptr<ShapeFactory> factory);

private:
	std::shared_ptr<Shape> createShape(std::shared_ptr<ShapeFactory> factory, int level);
	void printMenu(int level) const;
	void printIndent(int level) const;

	std::shared_ptr<Shape> createCircle(std::shared_ptr<ShapeFactory> factory, int level);
	std::shared_ptr<Shape> createRectangle(std::shared_ptr<ShapeFactory> factory, int level);
	std::shared_ptr<Shape> createComposite(std::shared_ptr<ShapeFactory> factory, int level);


	MenuChoice getMenuChoise();

};