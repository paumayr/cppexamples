
#include "Body.hpp"

void Body::accept(CarPartVisitor &visitor)
{
	visitor.accept(*this);
}