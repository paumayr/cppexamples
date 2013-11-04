#include "stdafx.h"
#include "CppUnitTest.h"

#include <future>
#include <filesystem>
#include <atomic>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


TEST_CLASS(TestAtomics)
{
	static void atomic_worker_increment(atomic<int> &variable)
	{
		for (int i = 0; i < 100; i++)
		{
			variable++;
		}
	}

	static void atomic_worker_decrement(atomic<int> &variable)
	{
		for (int i = 0; i < 100; i++)
		{
			variable--;
		}
	}

	TEST_METHOD(TestAtomicIncrement)
	{
		atomic<int> variable(0);

		vector<future<void>> v;

		for (int t = 0; t < 1000; t++)
		{
			v.emplace_back(async(atomic_worker_increment, ref(variable)));
			v.emplace_back(async(atomic_worker_decrement, ref(variable)));
		}
		
		for (auto& f : v) f.wait();

		Assert::IsTrue(0 == variable);
	}

};