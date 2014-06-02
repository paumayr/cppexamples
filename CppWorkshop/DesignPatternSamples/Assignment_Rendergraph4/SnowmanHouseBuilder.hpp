#pragma once

#include "ShapeBuilder.hpp"

class SnowmanHouseBuilder : public ShapeBuilder
{
public:
	virtual std::shared_ptr<Shape> LoadShape(std::shared_ptr<ShapeFactory> shapeFactory);
};