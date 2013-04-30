#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VC2012Test
{	
	using namespace std;

	
	TEST_CLASS(Vectorizer)
	{
	public:
		TEST_METHOD(TestVectorization)
		{
			float x1, y1, z1, w1;
			float x2, y2, z2, w2;

			x1 = y1 = z1 = w1 = 1.0f;
			x2 = y2 = z2 = w2 = 2.0f;

			float x = x1 + x2;
			float y = y1 + y2;
			float z = z1 + z2;
			float w = w1 + w2;
		}
	};
}