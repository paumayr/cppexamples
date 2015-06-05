#include "stdafx.h"
#include "CppUnitTest.h"

#include <chrono>
#include <thread>
#include <ctime>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(TestChrono)
{
	TEST_METHOD(TestSystemClock)
	{
		using namespace std::chrono;

		auto p1 = system_clock::now();
		this_thread::sleep_for(seconds(3));
		auto p2 = system_clock::now();

		auto dif = duration_cast<milliseconds>(p2 - p1).count();

		Assert::IsTrue(dif >= 3000);
	}
};