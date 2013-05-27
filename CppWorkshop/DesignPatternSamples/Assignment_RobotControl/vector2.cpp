
#include "vector2.h"

vector2::vector2()
	: x(0), y(0)
{
}
	
vector2::vector2(int _x, int _y)
	: x(_x), y(_y)
{
}

vector2 operator+(vector2& lh, vector2& rh)
{
	return vector2(lh.x + rh.x, lh.x + rh.x);
}