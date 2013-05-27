

#include "RobotControl.hpp"

class TestControl : public RobotControl
{
public:
	double temperatures[100 * 100];
	
	virtual double TakeMeasurement() const
	{
		vector2 pos = this->GetCurrentPosition();
		if (pos.x >= 0 && pos.x < 100 && pos.y >= 0 && pos.y < 100)
		{
			return temperatures[pos.y * 100 + pos.x];
		}

		return -1.0;
	}
};