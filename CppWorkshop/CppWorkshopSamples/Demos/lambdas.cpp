#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <functional>
#include <vector>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Demos
{
	TEST_CLASS(Lambdas)
	{
		TEST_METHOD(TestLambdaFunctionAdd)
		{
			class Add
			{
			public:
				int operator()(int a, int b) { return a + b; }
			};

			Add addOld;
			auto resultOld = addOld(5, 2);

			Assert::AreEqual(10, addOld(7, 3));
			Assert::AreEqual(20, addOld(10, 10));

			auto add = [](int a, int b) { return a + b; };
			auto result = add(5, 4);

			Assert::AreEqual(9, result);
			Assert::AreEqual(10, add(7, 3));
		}

		TEST_METHOD(TestLambdaFunctionCaptureValue)
		{
			auto toadd = 2;

			// explicit capture
			auto add = [toadd](int lh) { return lh + toadd; };
			Assert::AreEqual(7, add(5));

			// can implicit capture
			auto add2 = [=](int lh) { return lh + toadd; };

			Assert::AreEqual(7, add2(5));

			static_assert(sizeof(int) == sizeof(add), "sizeof add must be the size of an int");
		}

		TEST_METHOD(TestLambdaFunctionCaptureReference)
		{
			auto toadd = 2;
			auto add = [&toadd](int lh) { return lh + toadd; };
			auto sameasadd = [&](int lh) { return lh + toadd; };

			// now adds 2
			Assert::AreEqual(7, add(5));

			toadd = 3;
			// now adds 3
			Assert::AreEqual(8, add(5));
		}

		TEST_METHOD(TestLambdaFunctionMultiCapture)
		{
			auto lh = 2;
			auto rh = 5;
			auto add = [&lh, rh]() { return lh + rh; };

			Assert::AreEqual(7, add());

			lh = 3;
			Assert::AreEqual(8, add());

			rh = 6;
			Assert::AreEqual(8, add());
		}

		TEST_METHOD(TestLambdaFunctionType)
		{
			auto lambda1 = []() -> int { return 42; };
			auto lambda2 = []() -> int { return 32; };

			// will not compile, as every lambda has a different type
			//lambda1 = []() -> int{return 42; };
		}

		int eval(std::function<int(int)> f, int value)
		{
			return f(value);
		}

		TEST_METHOD(TestLambdaFunctionPassToFunction)
		{
			auto dup = [](int v){ return v * 2; };
			Assert::AreEqual(10, eval(dup, 5));
		}

		TEST_METHOD(TestLambdaFunctionInCollection)
		{
			std::vector<std::function<double(double)>> my_simple_pow =
			{
				[](double x) -> double { return 1; },
				[](double x) -> double { return x; },
				[](double x) -> double { return x*x; },
				[](double x) -> double { return x*x*x; },
			};

			Assert::AreEqual(1.0, my_simple_pow[0](12132.0));
			Assert::AreEqual(10.0, my_simple_pow[1](10.0));
			Assert::AreEqual(100.0, my_simple_pow[2](10.0));
			Assert::AreEqual(1000.0, my_simple_pow[3](10.0));
		}


		TEST_METHOD(TestLambdaSizeOf)
		{
			auto lambda1 = [](int, int, int) {};
			static_assert(1 == sizeof(lambda1), "size of empty lambda must be 1");

			int localvar = 1;
			auto lambda2 = [localvar]() -> int { return localvar; };
			static_assert(sizeof(int) == sizeof(lambda2), "size of lambda capturing an integer");

			int localvar2 = 2;
			auto lambda3 = [localvar, localvar2]() -> int { return localvar + localvar2; };
			static_assert(sizeof(int)* 2 == sizeof(lambda3), "size of lambda capturing two integers");

			int a, b, c;
			c = 7;
			auto lambda4 = [&]() -> int { return localvar + localvar2 + a; };
			static_assert(sizeof(int&)* 3 == sizeof(lambda4), "sizeof lambda capturing 3 references");
		}

		class Double
		{
		public:
			int operator()(int x)
			{
				return x * 2;
			}
		};

		TEST_METHOD(TestLambdaFunctionTransform)
		{
			using namespace std;
			// most simplistic lambda: no capture, no params, does nothing
			auto l = [](){};
			// .. but we can call it
			l();

			// (slightly) more realisitc
			vector<int> mynumbers;
			for (int i = 0; i < 4; i++) mynumbers.push_back(i);

			// we used to use the STL with functors (see above)
			Double f;
			Assert::AreEqual(4, f(2));
			transform(begin(mynumbers), // input start
				end(mynumbers), // input end
				begin(mynumbers), // output start
				Double());

			// .. instead we can now directly specify the logic where it is used.
			transform(begin(mynumbers),
				end(mynumbers),
				begin(mynumbers),
				[](int x) { return x * 2; } // transform
			);

			Assert::AreEqual(0, mynumbers[0]);
			Assert::AreEqual(4, mynumbers[1]);
			Assert::AreEqual(8, mynumbers[2]);
			Assert::AreEqual(12, mynumbers[3]);
		}

		TEST_METHOD(TestLambdaFunctionFilter)
		{
			using namespace std;

			vector<int> mynumbers;
			for (int i = 4; i < 10; i++)
			{
				mynumbers.push_back(i);
			}

			Assert::IsTrue(all_of(begin(mynumbers), end(mynumbers), [](int x) { return x > 3; }));

			auto posof5 = find_if(begin(mynumbers), end(mynumbers), [](int x) { return x == 5; });
		}

		static void my_function(int &variable)
		{
			variable++;
		}

		TEST_METHOD(TestFunctionCapture)
		{
			int myVariable = 0;

			// first guess: 
			function<void()> func = bind(my_function, myVariable);

			// Correct: function<void()> func = bind(my_function, ref(myVariable));
			func();

			Assert::AreEqual(myVariable, 0);
		}

		TEST_METHOD(TestSTLSortUsingLambda)
		{
			using namespace std;
			struct range
			{
				int upper;
				int lower;

				range(int u, int l) : upper(u), lower(l) {};
			};

			vector<range> mynumbers;
			generate_n(back_inserter(mynumbers), 10, []() -> range { return range(rand(), rand()); });
			sort(begin(mynumbers), end(mynumbers), [](range lh, range rh) -> bool { return lh.lower == rh.lower ? lh.lower < rh.lower : lh.upper < rh.upper; });
		}

	};
}