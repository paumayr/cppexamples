#pragma once
#include <string>
#include "CarPart.hpp"

class Wheel : public CarPart
{
	std::string name;
public:
	Wheel (std::string _name);
	const std::string& getName() const;

	virtual void accept(CarPartVisitor &visitor);
};