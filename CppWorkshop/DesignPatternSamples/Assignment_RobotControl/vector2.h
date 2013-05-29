#pragma once

class vector2
{
public:
	vector2();
	vector2(int _x, int _y);

	int x, y;
};

vector2 operator+(vector2& lh, vector2& rh);