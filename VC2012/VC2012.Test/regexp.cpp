#include "stdafx.h"
#include "CppUnitTest.h"
#include <regex>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VC2012Test
{	
	using namespace std;

	TEST_CLASS(RegularExpressions)
	{
	public:
		TEST_METHOD(TestRegularExpressions)
		{
			std::regex expr("");
		}
	};
	}