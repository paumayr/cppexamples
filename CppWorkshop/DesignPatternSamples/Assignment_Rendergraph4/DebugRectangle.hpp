#pragma once

#include "Rectangle.hpp"

class DebugRectangle : public Rectangle
{
public:
	virtual void accept(ShapeVisitor &visitor);
};
