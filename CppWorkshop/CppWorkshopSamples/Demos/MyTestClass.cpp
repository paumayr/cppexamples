
#include "stdafx.h"
#include "CppUnitTest.h"

#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(MyTestClass)
{
	TEST_METHOD(MyTestMethod)
	{
		int somevar = 10;
		int other = 20;
		int sum = somevar + other;

		stringstream ss;
		ss << sum;
		Logger::WriteMessage(ss.str().c_str());
		Assert::IsTrue(sum == 30);
	}
};