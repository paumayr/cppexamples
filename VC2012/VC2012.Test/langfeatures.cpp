#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include <functional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VC2012Test
{		
	TEST_CLASS(LanguageFeatures)
	{
	public:
		TEST_METHOD(TestAuto)
		{
			int a = 10;
			auto b = a;
			auto& c = a;
			auto* d = &a;

			Assert::IsNotNull(d);
		}

		TEST_METHOD(TestAuto2)
		{
			std::vector<int> mynumbers;
			mynumbers.push_back(1);
			mynumbers.push_back(2);
			mynumbers.push_back(3);
			mynumbers.push_back(4);

			int sum = 0;
			for(auto it = begin(mynumbers); it != end(mynumbers); it++)
			{
				sum += *it;
			}

			Assert::AreEqual(10, sum);
		}
 
		TEST_METHOD(TestDeclType)
		{
			int a = 10;
			decltype(a) b;
			b = a;

			Assert::AreEqual(a, b);

			decltype(a * 10.0f) c = a * 10.0f;
			// c is a float
			Assert::AreEqual(100.0f, c);
		}

		TEST_METHOD(TestRangeBasedForLoop)
		{
			std::vector<int> mynumbers;

			mynumbers.push_back(1);
			mynumbers.push_back(2);
			mynumbers.push_back(3);
			mynumbers.push_back(4);

			int sum = 0;
			for (auto x : mynumbers)
			{
				sum += x;
			}

			Assert::AreEqual(10, sum);
		}

		TEST_METHOD(TestRangeBasedForLoopArray)
		{
			int numbers[] = {1, 2, 3, 4, 5};
			for(auto x : numbers)
			{

			}

			// equivalent to (if numbers is an array)
			for(auto begin = numbers, end = numbers + _countof(numbers); begin != end; ++begin)
			//for(auto begin = numbers, end = numbers + sizeof(numbers); begin != end; ++begin)
			{
				auto x = *begin;
			}
		}



		class Range
		{
		public:
			class iterator 
			{
				friend class Range;
			public:
				long int operator *() const { return i; }
				const iterator &operator ++() { ++i; return *this; }
				iterator operator ++(int) { iterator copy(*this); ++i; return copy; }

				bool operator ==(const iterator &other) const { return i == other.i; }
				bool operator !=(const iterator &other) const { return i != other.i; }

			protected:
				iterator(long int start) : i (start) { }

			private:
				unsigned long i;
			};

			Range(int lowerBoundInclusive, int upperBoundExclusive)
				: lowerBound(lowerBoundInclusive), upperBound(upperBoundExclusive)
			{}

			iterator lowerBound, upperBound;

			iterator begin() const { return lowerBound; }
			iterator end() const { return upperBound; }
		};

		TEST_METHOD(TestRangeBasedForLoopCustomRange)
		{
			for (auto x : Range(1, 10))
			{
			}
		}

		TEST_METHOD(TestLambdaFunctionAdd)
		{
			class Add
			{
			public:
				int operator()(int a, int b) { return a + b; }
			};

			Add addOld;
			auto result = addOld(5, 2);

			Assert::AreEqual(10, addOld(7, 3));
			Assert::AreEqual(20, addOld(10, 10));

			auto add = [](int a, int b) { return a + b; };
			//auto result = add(5, 4);

			Assert::AreEqual(10, add(7, 3));
			Assert::AreEqual(20, add(10, 10));
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

		int eval(std::function<int(int)> f, int value)
		{
			return f(value);
		}

		TEST_METHOD(TestLambdaFunctionPassToFunction)
		{
			auto dup = [](int v){ return v * 2;};
			Assert::AreEqual(10, eval(dup, 5));
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
						f);

			// .. instead we can now directly speciy the logic where it is used.
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
			sort(begin(mynumbers), end(mynumbers), [](range lh, range rh) -> bool { return lh.lower == rh.lower ? lh.lower < rh.lower :  lh.upper < rh.upper; });
		}


		TEST_METHOD(TestStaticAssert)
		{
			static_assert(sizeof(int) == 4, "sizeof int is not 4 bytes");
		}
	};
}