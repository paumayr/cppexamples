
#pragma once

#include <cmath>

class Vector3Setter
{
public:
	Vector3Setter() : x(0.0), y(0.0), z(0.0), length_calculated(false) { }

	double getLength()
	{
		if (length_calculated)
		{
			return length;
		}

		length = sqrt(x*x+y*y+z*z);
		length_calculated = true;
		return length;
	}

	void SetX(double _x) {

		this->x = _x;
		length_calculated = false;
	}
private:
	double x, z, y;
	double length;
	bool length_calculated;
};