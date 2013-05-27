#pragma once

#include "vector2.h"

class RobotControl
{
	vector2 currentPosition;
public:
	virtual void MoveArm(vector2 delta)
	{
		currentPosition = currentPosition + delta;
	}
	
	virtual vector2 GetCurrentPosition() const
	{
		return currentPosition;
	}

	virtual double TakeMeasurement() const = 0;
};