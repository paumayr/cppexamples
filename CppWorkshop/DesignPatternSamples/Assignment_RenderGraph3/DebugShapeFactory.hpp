#pragma once

#include "ShapeFactory.hpp"

class DebugShapeFactory : public ShapeFactory
{
public:
	std::tr1::shared_ptr<CompositeShape> CreateComposite() const;
	std::tr1::shared_ptr<Circle> CreateCircle(const vector2f &center, float radius) const;
	std::tr1::shared_ptr<Rectangle> CreateRectangle(const vector2f &point, float width, float height) const;
};