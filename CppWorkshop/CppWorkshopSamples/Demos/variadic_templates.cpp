#include "stdafx.h"
#include "CppUnitTest.h"
#include <algorithm>
#include <tuple>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


TEST_CLASS(VariadicTemplates)
{
	/*
	Argument count
	*/
	template<typename T, typename... Args>
	int count(T t, Args... args)
	{
		return 1 + count(args...);
	}

	int count()
	{
		return 0;
	}

	TEST_METHOD(TestVariadicArgumentCount)
	{
		Assert::AreEqual(4, count(1, 2, 3, 4));
	}

	template<typename... Args>
	int countSizeof(Args... args)
	{
		return sizeof...(args);
	}

	TEST_METHOD(TestVariadicArgumentSizeof)
	{
		Assert::AreEqual(4, countSizeof(1, 2, 3, 4));
	}

	/*
	Safe printing
	*/
	void safeprint(std::ostream &out, int x)
	{
		out << x << "i";
	}

	void safeprint(std::ostream &out, float x)
	{
		out << x << "f";
	}

	void safeprint(std::ostream &out, double x)
	{
		out << x << "d";
	}

	template<typename T, typename... Args>
	void safeprint(std::ostream &out, T current, Args... rest)
	{
		safeprint(out, current);
		out << ' ';
		safeprint(out, rest...);
	}

	TEST_METHOD(TestSafePrint)
	{
		std::string expected = "10i 10.1f 10.123d";
		std::stringstream output;
		safeprint(output, 10, 10.10f, 10.123);

		Assert::AreEqual(expected, output.str());
	}

	/*
	Minimum variadic count
	*/
	template<typename T, typename... Args>
	T varmin(T current, Args... rest)
	{
		return std::min(current, varmin(rest...));
	}

	template<typename T>
	T varmin(T current)
	{
		return current;
	}

	TEST_METHOD(TestStaticMin)
	{
		Assert::AreEqual(5, varmin(10, 7, 13, 5, 8, 9));
	}
};