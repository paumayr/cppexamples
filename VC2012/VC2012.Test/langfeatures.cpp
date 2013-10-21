#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <tuple>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VC2012Test
{		
	TEST_CLASS(LanguageFeatures)
	{
	public:
		TEST_METHOD(TestAutoMotivation)
		{
			{
				// full typing everything
				std::vector<std::tuple<int, int, int>> my_collection{};
				std::tuple<int, int, int> a = std::make_tuple(1, 2, 3);
				my_collection.push_back(a);
				for (std::vector<std::tuple<int, int, int>>::iterator it = my_collection.begin(); it != my_collection.end(); ++it)
				{
					// do something with tuple.
				}
			}

			{
			// with type def
			typedef std::tuple<int, int, int> my_tuple_type;
			typedef std::vector<my_tuple_type> my_collection_type;
			my_collection_type my_collection;
			my_tuple_type a = my_tuple_type(1, 2, 3);
			my_collection.push_back(a);
			for (my_collection_type::iterator it = my_collection.begin(); it != my_collection.end(); ++it)
			{
				// do something with tuple
			}
		}

			{
				// with auto
				std::vector<std::tuple<int, int, int>> my_collection{};
				auto a = std::make_tuple(1, 2, 3);
				my_collection.push_back(a);
				for (auto it = my_collection.begin(); it != my_collection.end(); ++it)
				{
					// do something with tuple
				}
			}
		}

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
 
		TEST_METHOD(TestAutoQualifiers)
		{
			const int a = 5;
			auto b = a;
			b = 20; // valid, because b is not const

			int c = 10;
			int &d = c;
			// auto drops reference qualifier
			auto e = d; // e is not a reference to d / c

			e = 12;
			Assert::AreEqual(10, c);
			Assert::AreEqual(12, e);
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

		TEST_METHOD(TestDeclTypeQualifiers)
		{
			const int a = 10;
			decltype(a) b = 20;
			// will not compile, b is "const int"
			// b = 10; 

			int c = 5;
			int &d = c;
			decltype(d) e = c;

			// e is a reference to c (as decltype(d) == "int &")
			e = 10;
			Assert::AreEqual(10, c);
			Assert::AreEqual(10, e);
		}


		auto some_function() -> int
		{
			return 42;
		}

		template<typename T>
		auto add(T lh, T rh) -> decltype(lh + rh)
		{
			return lh + rh;
		}

		TEST_METHOD(TestRangeBasedForLoop)
		{
			//// pre VS 2013
			////std::vector<int> mynumbers;

			////mynumbers.push_back(1);
			////mynumbers.push_back(2);
			////mynumbers.push_back(3);
			////mynumbers.push_back(4);

			auto mynumbers = { 1, 2, 3, 4 };
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
			for (auto x : Range(10, 20))
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
			// lambda1 = []() -> int{return 42; };
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
						f);

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