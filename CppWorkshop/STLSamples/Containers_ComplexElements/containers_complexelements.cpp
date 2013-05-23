
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct point2f
{
	point2f(float _x, float _y)
		: x(_x), y(_y)
	{}

	float x;
	float y;
};

int main(int argc, char **argv)
{
	vector<point2f> points;

	points.push_back(point2f(1.0f, 2.0f));
	points.push_back(point2f(3.0f, 4.0f));

	points[1].x *= 4.0f;

	for_each(begin(points), end(points),
		[](point2f &p) { cout << "(" << p.x << "," << p.y << ")" << endl; });


	cin.get();
	return 0;
}