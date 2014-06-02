#pragma once

#include <memory>

#include "vector2.hpp"

class CompositeShape;
class Circle;
class Rectangle;


class ShapeFactory
{
public:
	virtual std::shared_ptr<CompositeShape> CreateComposite() const = 0;
	virtual std::shared_ptr<Circle> CreateCircle(const vector2f &center, float radius) const = 0;
	virtual std::shared_ptr<Rectangle> CreateRectangle(const vector2f &point, float width, float height) const = 0;
};