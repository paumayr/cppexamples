#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace Demos
{
	struct vector2
	{
		double x, y;
	};

	vector2 operator+(const vector2& lh, const vector2& rh)
	{
		return vector2{ lh.x + rh.x, lh.y + rh.y };
	}

	vector2 operator*(const vector2& lh, double factor)
	{
		return vector2{ lh.x * factor, lh.y * factor };
	}

	vector2 operator*(double factor, const vector2& lh)
	{
		return lh * factor;
	}

	TEST_CLASS(OperatorOverload)
	{
		TEST_METHOD(TestOverload)
		{
			vector2 a, b, c;
			c = a + b;
			c = c * 3.0;
			c = 3.0 *c;
		}
	};
}