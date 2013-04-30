#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <future>
#include <ppltasks.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VC2012Test
{	
	using namespace std;

	TEST_CLASS(Async)
	{
	public:

		static double complexCompute(double value, int iterations)
		{
			for (int i = 0; i < iterations; i++)
			{
				value = asin(sin(acos(cos(value))));
			}

			return value;
		}

		TEST_METHOD(TestAsync)
		{
			using namespace std;

			vector<future<double>> results;

			for (double i = 0.0; i < 2000.0; i += 1.0)
			{
				results.push_back(async(launch::async, complexCompute, 10.0, 1000000));
			}

			for (auto &x : results)
			{
				auto value = x.get();
			}
		}

		TEST_METHOD(TestTaskPPL)
		{
			using namespace std;
			using namespace concurrency;

			vector<task<double>> results;

			for (double i = 0.0; i < 10.0; i += 1.0)
			{
				results.push_back(task<double>([]() 
				{
					return complexCompute(10.0, 1000000);
				}));
			}

			bool finished = false;
			auto calc = when_all(results.begin(), results.end())
				.then([&](vector<double> result) { finished = true;});
			
			calc.get();

			Assert::IsTrue(finished);
		}

		TEST_METHOD(TestPromise)
		{
			std::promise<int> promise;

			auto computation = [&promise]() {
				int res = 42; // yes, this was complicated!
				promise.set_value(res);
			};

			std::thread t(computation);

			auto future = promise.get_future();

			int value = future.get();

			Assert::AreEqual(42, value);

			t.join(); // make sure worker thread is correctly joined.
		}
	};
}