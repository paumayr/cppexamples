#pragma once 

#include "CarPartVisitor.hpp"

class CarPart
{
public:
	virtual void accept(CarPartVisitor &visitor) = 0;
};