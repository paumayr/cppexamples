#include "DebugShapeFactory.hpp"
#include "DebugShapes.hpp"


std::shared_ptr<CompositeShape> DebugShapeFactory::CreateComposite() const
{
	return std::shared_ptr<CompositeShape>(new DebugCompositeShape());
}

std::shared_ptr<Circle> DebugShapeFactory::CreateCircle(const vector2f &center, float radius) const
{
	return std::shared_ptr<Circle>(new DebugCircle(center, radius));
}

std::shared_ptr<Rectangle> DebugShapeFactory::CreateRectangle(const vector2f &point, float width, float height) const
{
	return std::shared_ptr<Rectangle>(new DebugRectangle(point, width, height));
}
