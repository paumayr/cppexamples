
#include "RobotControl.hpp"

class E3000Control : RobotControl
{
public:
	virtual void MoveArm(vector2 delta)
	{
		RobotControl::MoveArm(delta);
	}

	virtual double TakeMeasurement() const
	{
		// somehow call serial port, and communicate with sensor
	}
};