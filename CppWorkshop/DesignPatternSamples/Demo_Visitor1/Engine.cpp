#include "Engine.hpp"

void Engine::accept(CarPartVisitor &visitor)
{
	visitor.accept(*this);
}