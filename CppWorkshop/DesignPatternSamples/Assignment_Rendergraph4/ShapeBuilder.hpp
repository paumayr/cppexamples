#pragma once

#include <memory>

class Shape;
class ShapeFactory;
// ShapeBuilder is the abstract interface for all shape builders.
// shapes can be built by calling the load shape method.
class ShapeBuilder
{
public:
	virtual ~ShapeBuilder() {};
	virtual std::tr1::shared_ptr<Shape> LoadShape(std::tr1::shared_ptr<ShapeFactory> factory) = 0;
};
