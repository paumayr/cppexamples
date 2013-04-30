#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>

#include "Vector2.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VC2012Test
{		
	TEST_CLASS(Vector2Test)
	{
	public:
		TEST_METHOD(TestVector)
		{
			MyVector2 a(1.0f, 2.0f);

			MyVector2 b(0.0f, 0.0f);

			std::vector<int> myvectorinstance(25);
			for(int i = 0; i < 25; i++) { myvectorinstance.push_back(i); }

			// use debugger to show visualizer
		}
	};
}