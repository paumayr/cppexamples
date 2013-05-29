#pragma once 

#include "CarPart.hpp"

class Body : public CarPart
{
public:
	virtual void accept(CarPartVisitor &visitor);
};