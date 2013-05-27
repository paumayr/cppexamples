#include "DebugShapeFactory.hpp"
#include "DebugShapes.hpp"


std::tr1::shared_ptr<CompositeShape> DebugShapeFactory::CreateComposite() const
{
	return std::tr1::shared_ptr<CompositeShape>(new DebugCompositeShape());
}

std::tr1::shared_ptr<Circle> DebugShapeFactory::CreateCircle(const vector2f &center, float radius) const
{
	return std::tr1::shared_ptr<Circle>(new DebugCircle(center, radius));
}

std::tr1::shared_ptr<Rectangle> DebugShapeFactory::CreateRectangle(const vector2f &point, float width, float height) const
{
	return std::tr1::shared_ptr<Rectangle>(new DebugRectangle(point, width, height));
}
