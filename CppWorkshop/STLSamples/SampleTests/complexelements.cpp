#include "stdafx.h"
#include "CppUnitTest.h"

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SampleTests
{		
	TEST_CLASS(ComplexElements)
	{
	public:


		struct point2f
		{
			point2f(float _x, float _y)
				: x(_x), y(_y)
			{}

			float x;
			float y;
		};

		
		TEST_METHOD(TestComplexElements)
		{
			vector<point2f> points;

			points.push_back(point2f(1.0f, 2.0f));
			points.push_back(point2f(3.0f, 4.0f));

			points[1].x *= 4.0f;

			for_each(begin(points), end(points),
				[](point2f &p) { cout << "(" << p.x << "," << p.y << ")" << endl; });
		}
	};
}