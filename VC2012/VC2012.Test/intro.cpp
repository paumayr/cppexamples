#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VC2012Test
{		
	TEST_CLASS(IntroTests)
	{
	public:
		
		TEST_METHOD(TestMethod)
		{
			Assert::IsFalse(false, L"message", LINE_INFO());
		}

	};
}