
#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <vector>
#include <functional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(TestFunctional)
{

	static void incrementValue(int &value)
	{
		value += 3;
	}

	TEST_METHOD(TestFunctional1)
	{
		int myvalue = 0;
		incrementValue(myvalue);
		Assert::AreEqual(3, myvalue);

		auto f = function<void(int &)>(incrementValue);

		f(myvalue);
		Assert::AreEqual(6, myvalue);

		auto f1 = std::bind(incrementValue, ref(myvalue));

		f1();
		Assert::AreEqual(9, myvalue);
	}
};