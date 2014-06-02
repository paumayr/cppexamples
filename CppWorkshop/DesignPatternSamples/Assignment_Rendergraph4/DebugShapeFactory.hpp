#pragma once

#include "ShapeFactory.hpp"

class DebugShapeFactory : public ShapeFactory
{
public:
	virtual ~DebugShapeFactory() {};
	std::shared_ptr<CompositeShape> CreateComposite() const;
	std::shared_ptr<Circle> CreateCircle(const vector2f &center, float radius) const;
	std::shared_ptr<Rectangle> CreateRectangle(const vector2f &point, float width, float height) const;
};