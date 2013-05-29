#pragma once

#include "ShapeVisitor.hpp"

class RenderShapeVisitor : public ShapeVisitor
{
	int indentLevel;
public:
	RenderShapeVisitor();
	virtual void beginComposite(CompositeShape &shape);

	virtual void visit(Rectangle &rectangle);
	virtual void visit(Circle &circle);

	virtual void endComposite(CompositeShape &shape);
private:
	void printIndent();
};