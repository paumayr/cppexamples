#pragma once

#include "ShapeBuilder.hpp"

class SnowmanHouseBuilder : public ShapeBuilder
{
public:
	virtual std::tr1::shared_ptr<Shape> LoadShape(std::tr1::shared_ptr<ShapeFactory> shapeFactory);
};