#include "stdafx.h"
#include "CppUnitTest.h"

#include <algorithm>
#include "boost/regex.hpp"

#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Demo_Boost
{
	TEST_CLASS(Regex)
	{
	public:
		TEST_METHOD(TestBasicRegularExpression)
		{
			using namespace boost;

			boost::regex identifier("[a-z][a-zA-Z0-9]*");

			Assert::IsTrue(regex_match("myVariable10", identifier));
			Assert::IsFalse(regex_match("MyVariable10", identifier));
		}
	};
}