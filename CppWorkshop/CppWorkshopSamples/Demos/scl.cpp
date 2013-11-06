#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <functional>
#include <vector>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Demos
{
	TEST_CLASS(TestSCL)
	{
		TEST_METHOD(TestVectorOutOfBound)
		{
			vector<int> v{ 1, 2, 3, 4 };
			v[3] = 10;
		}
	};
}