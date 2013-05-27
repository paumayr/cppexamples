
#include "RobotControl.hpp"

vector2 FindHottestSpot(RobotControl& control)
{
	double hottest = -10000.0;
	vector2 hottestPosition;

	for(int y = 0; y < 100; y++)
	{
		for(int x = 0; x < 100; x++)
		{
			control.MoveArm(vector2(1, 0));
			double currentMeasurement = control.TakeMeasurement();

			if (currentMeasurement > hottest)
			{
				hottest = currentMeasurement;
				hottestPosition.x = x;
				hottestPosition.y = y;
			}
		}

		control.MoveArm(vector2(-100, 1));
	}

	return hottestPosition;
}