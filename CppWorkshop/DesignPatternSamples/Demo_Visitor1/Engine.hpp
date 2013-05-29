#pragma once

#include "CarPart.hpp"

class Engine : public CarPart
{
public:
	virtual void accept(CarPartVisitor &visitor);
};