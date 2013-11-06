#include "stdafx.h"
#include "CppUnitTest.h"
#include "boost/lexical_cast.hpp"

#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Demo_Boost
{		
	TEST_CLASS(LexicalCast)
	{
	public:
		
		TEST_METHOD(TestLexicalFromString)
		{
			using namespace boost;
			Assert::IsTrue(10 == lexical_cast<int>("10"));
			Assert::IsTrue(10.0f == lexical_cast<float>("10.0"));
		}

		TEST_METHOD(TestLexicalToString)
		{
			using namespace std;
			using namespace boost;

			Assert::IsTrue("10" == lexical_cast<string>(10));
		}
	};
}