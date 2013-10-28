#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <vector>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(STLAlgorithms)
{
	template<typename T>
	auto Range(T min, T max) -> std::vector<T>
	{
		std::vector<T> result;
		result.reserve(max - min);
		for (auto c = min; c < max; c++)
		{
			result.push_back(c);
		}

		return result;
	}

	TEST_METHOD(TestTransform)
	{
		auto vec = Range(0, 10);
		decltype(vec) doubled(vec.size());

		// transforms reads each element
		// maps the function (lambda here) to the element
		// writes to the iterator pointing to the first element of double.
		transform(begin(vec), end(vec), begin(doubled), [](const int &x) { return x * 2; });

		// assert result
		for (size_t i = 0; i < vec.size(); i++)
		{
			Assert::AreEqual(vec[i] * 2, doubled[i]);
		}
	}

	TEST_METHOD(TestFind)
	{
		auto vec = Range(0, 10);

		// iterators for range (begin, end)
		auto pos = find(begin(vec), end(vec), 5);
		
		Assert::IsTrue(vec.begin() + 5 == pos);
	}

	TEST_METHOD(TestFindIf)
	{
		auto vec = Range(0, 10);

		auto pos = find_if(begin(vec), end(vec), [](int &x) { return x > 5; });

		Assert::IsTrue(begin(vec) + 6 == pos);
	}

	TEST_METHOD(TestShuffleAndSort)
	{
		auto vec = Range(0, 10);
		auto vec2 = vec;
		Assert::IsTrue(vec2 == vec);

		// shuffle elements in vector randomly
		random_shuffle(begin(vec), end(vec));

		Assert::IsFalse(vec2 == vec);

		// sort the elements
		sort(begin(vec), end(vec));

		Assert::IsTrue(vec2 == vec);
	}

	TEST_METHOD(TestLowerBoundAndUpperBound)
	{
		auto vec = Range(0, 10);
		// transform inplace, quad-druple value
		transform(begin(vec), end(vec), begin(vec), [](int &x) { return x * 4; });

		// lower_bound assumes container is sorted by operator<
		auto lb = lower_bound(begin(vec), end(vec), 35);
		Assert::IsTrue(all_of(begin(vec), lb, [](int &x) { return x < 35; }));

		// upper_bound assumes container is sorted by operator<
		auto ub = upper_bound(begin(vec), end(vec), 35);
		Assert::IsTrue(all_of(ub, end(vec), [](int &x) { return x >= 35; }));
	}

	TEST_METHOD(TestRotate)
	{
		vector<int> data = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		
		// move element at 5th position to
		rotate(begin(data), begin(data) + 5, end(data));

		vector<int> expected = { 5, 6, 7, 8, 9, 0, 1, 2, 3, 4 };

		Assert::IsTrue(expected == data);
	}

	TEST_METHOD(TestRotateComplexMove)
	{
		vector<int> data { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		// move 7 element to second position
		auto seventh = begin(data) + 7;
		auto second = begin(data) + 2;
		
		rotate(second, seventh, seventh + 1);

		vector<int> expected = { 0, 1, 7, 2, 3, 4, 5, 6, 8, 9 };

		Assert::IsTrue(expected == data);
	}

	TEST_METHOD(TestCopyIf)
	{
		vector<int> data { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };

		decltype(data) valuesGreater35;

		copy_if(begin(data), end(data), back_inserter(valuesGreater35), [](int &x) { return x > 35; });

		vector<int> expected { 40, 50, 60, 70, 80, 90 };
		
		Assert::IsTrue(expected == valuesGreater35);
	}

	TEST_METHOD(TestSetDifference)
	{
		vector<int> setA { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
		vector<int> setB{ 30, 40, 50 };

		decltype(setA) difference;

		// set difference
		set_difference(begin(setA), end(setA), begin(setB), end(setB), back_inserter(difference));

		vector<int> expected = { 0, 10, 20, 60, 70, 80, 90 };
		Assert::IsTrue(expected == difference);
	}

	TEST_METHOD(TestRemoveIf)
	{
		vector<int> a{ 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
		
		// remove elements greater than 35
		a.erase(remove_if(begin(a), end(a), [](int &x) { return x > 35; }), end(a));

		vector<int> expected{ 0, 10, 20, 30 };
		Assert::IsTrue(expected == a);
	}
};