#pragma once

#include <iostream>
#include "RobotControl.hpp"

class ConsoleOutControl : public RobotControl
{
public:
	virtual void MoveArm(vector2 delta)
	{
		RobotControl::MoveArm(delta);

		vector2 pos = this->GetCurrentPosition();
		std::cout << "Current Position: " << pos.x << " / " << pos.y << std::endl;
	}

	virtual double TakeMeasurement() const
	{
		double measurement;
		std::cin >> measurement;
		return measurement;
	}
};