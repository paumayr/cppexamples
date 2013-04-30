#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VC2012Test
{	
	using namespace std;

	TEST_CLASS(CodeCoverage)
	{
	public:
		TEST_METHOD(TestSieve)
		{
			int values[] = {2, 4, 6, 8, 10};

			vector<int> uneven;
			vector<int> even;

			for (auto x : values)
			{
				if (x % 2 != 0)
				{
					uneven.push_back(x);
				}
				else
				{
					even.push_back(x);
				}
			}
		}
	};
}