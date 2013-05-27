#include "StandardShapeFactory.hpp"

#include "CompositeShape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

std::tr1::shared_ptr<CompositeShape> StandardShapeFactory::CreateComposite() const
{
	return std::tr1::shared_ptr<CompositeShape>(new CompositeShape());
}

std::tr1::shared_ptr<Circle> StandardShapeFactory::CreateCircle(const vector2f &center, float radius) const
{
	return std::tr1::shared_ptr<Circle>(new Circle(center, radius));
}

std::tr1::shared_ptr<Rectangle> StandardShapeFactory::CreateRectangle(const vector2f &point, float width, float height) const
{
	return std::tr1::shared_ptr<Rectangle>(new Rectangle(point, width, height));
}
