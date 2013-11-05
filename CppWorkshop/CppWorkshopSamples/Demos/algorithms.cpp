#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <numeric>
#include <hash_map>
#include <tuple>

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

	/*
	Quantifiers
	*/
	TEST_METHOD(TestAllOf)
	{
		vector<int> a{ 10, 20, 30, 40, 50, 60, 70, 80, 90 };
		Assert::IsTrue(all_of(begin(a), end(a), [](int &x) { return x < 100; }));


		Assert::IsFalse(all_of(begin(a), end(a), [](int &x) { return x > 30; }));
	}

	TEST_METHOD(TestAnyOf)
	{
		vector<int> a{ 10, 20, 30, 40, 50, 60, 70, 80, 90 };
		Assert::IsTrue(any_of(begin(a), end(a), [](int &x) { return x < 20; }));
		Assert::IsFalse(any_of(begin(a), end(a), [](int &x) { return x > 100; }));
	}

	TEST_METHOD(TestNoneOf)
	{
		vector<int> a{ 10, 20, 30, 40, 50, 60, 70, 80, 90 };
		Assert::IsTrue(none_of(begin(a), end(a), [](int &x) { return x > 100; }));
		Assert::IsFalse(none_of(begin(a), end(a), [](int &x) { return x < 30; }));
	}

	/*
	Counting elements
	*/
	TEST_METHOD(TestCount)
	{
		vector<int> a{ 10, 20, 30, 40, 50, 60, 70, 80, 90, 30, 20, 10, 20, 30, 20, 10 };
		auto counts = count(begin(a), end(a), 20);
		Assert::IsTrue(4 == counts);
	}

	TEST_METHOD(TestCountIf)
	{
		vector<int> a{ 10, 20, 30, 40, 50, 60, 70, 80, 90 };
		auto counts = count_if(begin(a), end(a), [](int &x) { return x < 40; });
		Assert::IsTrue(3 == counts);
	}

	/*
	Mismatch
	*/
	TEST_METHOD(TestMismatch)
	{
		vector<int> a{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		vector<int> b{ 0, 1, 2, 4, 5, 6, 7, 8, 9, 10 };

		auto pos = mismatch(begin(a), end(a), begin(b));
		
		auto posInA = pos.first;
		auto posInB = pos.second;

		Assert::AreEqual(3, *posInA);
		Assert::AreEqual(4, *posInB);

		Assert::IsTrue(3 == distance(begin(a), posInA));
		Assert::IsTrue(3 == distance(begin(b), posInB));
	}

	TEST_METHOD(TestMismatchPredicate)
	{
		vector<int> a		{ 0, 1, 2, 3,  4,  5,  6,  7,  8,  9 };
		vector<int> squares { 0, 1, 4, 9, 16, 25, 36, 42, 64, 81 };

		auto pos = mismatch(begin(a), end(a), begin(squares), [](int &lh, int &rh) { return lh * lh == rh; });
		auto posInA = pos.first;
		auto posInB = pos.second;

		Assert::AreEqual(7, *posInA);
		Assert::AreEqual(42, *posInB);

		Assert::IsTrue(7 == distance(begin(a), posInA));
		Assert::IsTrue(7 == distance(begin(squares), posInB));
	}

	/*
	Test Searching ranges in ranges
	*/
	TEST_METHOD(TestSearch)
	{
		vector<int> a{ 17, 32, 25, 35, 48, 42, 13, 25, 35, 24 };

		// find all occurences of 25, 35 
		auto toFind = { 25, 35 };
		auto firstOccurence = search(begin(a), end(a), begin(toFind), end(toFind));

		Assert::IsTrue(2 == distance(begin(a), firstOccurence));

		// start search for next occurence one after the first occurence
		auto secondOccurence = search(firstOccurence + 1, end(a), begin(toFind), end(toFind));

		Assert::IsTrue(7 == distance(begin(a), secondOccurence));
	}

	/*
	Finding elements.
	*/
	TEST_METHOD(TestFind)
	{
		vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		auto pos = find(begin(vec), end(vec), 5);

		Assert::IsTrue(vec.begin() + 5 == pos);
	}

	TEST_METHOD(TestFindIf)
	{
		vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		auto pos = find_if(begin(vec), end(vec), [](int &x) { return x > 5; });

		Assert::IsTrue(begin(vec) + 6 == pos);

		
		pos = find_if(begin(vec), end(vec), [](int &x) { return x > 10; });
		Assert::IsTrue(pos == end(vec));
	}

	/*
	Copying elements
	*/
	TEST_METHOD(TestCopy)
	{
		std::vector<int> a{ 1, 2, 3, 4, 5 };
		std::vector<int> b{ 0, 0, 0, 0, 0 };

		copy(begin(a), end(a), begin(b));
		Assert::IsTrue(a == b);

		// if we don't yet have space in the target collection 
		// or want to append ...
		std::vector<int> c;
		
		// ... use a back_inserter
		copy(begin(a), end(a), back_inserter(c));

		Assert::IsTrue(a == c);
	}

	TEST_METHOD(TestCopyIf)
	{
		vector<int> data{ 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };

		decltype(data) valuesGreater35;

		copy_if(begin(data), end(data), 
			back_inserter(valuesGreater35), 
			[](int &x) { return x > 35; });

		vector<int> expected{ 40, 50, 60, 70, 80, 90 };
		Assert::IsTrue(expected == valuesGreater35);
	}

	/*
	removing consecutive duplicates
	*/
	TEST_METHOD(TestUnique)
	{
		vector<int> a{ 10, 20, 30, 30, 30, 40, 50, 50, 60, 60, 60, 70, 70, 80, 90 };
		
		// remove-erase paradigm!
		auto newLogicalEnd = std::unique(begin(a), end(a));

		vector<int> expected{ 10, 20, 30, 40, 50, 60, 70, 80, 90 };
		Assert::IsTrue(equal(begin(a), newLogicalEnd, begin(expected)));
		Assert::IsTrue(a.size() != expected.size());

		// erase new end element.
		a.erase(newLogicalEnd, end(a));

		Assert::IsTrue(a == expected);
		Assert::IsTrue(a.size() == expected.size());
	}

	/*
	Transforming values of a collection.
	*/
	TEST_METHOD(TestTransform)
	{
		std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		decltype(vec) doubled(vec.size());

		// transforms reads each element
		// for each element:
		//   maps the function (lambda here) to the element
		//   writes to the iterator pointing to the element of double.
		//   increments the output iterator 
		transform(begin(vec), end(vec), begin(doubled), 
				[](const int &x) { return x * 2; });

		// assert result
		for (size_t i = 0; i < vec.size(); i++)
		{
			Assert::AreEqual(vec[i] * 2, doubled[i]);
		}
	}

	/*
	Removing elements
	*/
	TEST_METHOD(TestRemove)
	{
		vector<int> a{ 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };

		// remove 10
		// does so by copying elements to the front to fill "holes"
		auto newEnd = remove(begin(a), end(a), 10);
		Assert::IsTrue(distance(a.begin(), newEnd) == 9);

		vector<int> aAfterRemove{ 0, 20, 30, 40, 50, 60, 70, 80, 90, 90 };
		Assert::IsTrue(aAfterRemove == a);

		// erase from the new end
		a.erase(newEnd, a.end());

		// a now contains all but 10
		vector<int> expected{ 0, 20, 30, 40, 50, 60, 70, 80, 90 };
		Assert::IsTrue(expected == a);
	}

	TEST_METHOD(TestRemoveShort)
	{
		vector<int> a{ 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };

		// remove-erase paradigm
		// short hand: vector.erase(from, to), from = new end of collection.
		a.erase(remove(begin(a), end(a), 10), a.end());

		// a now contains all but 10
		vector<int> expected{ 0, 20, 30, 40, 50, 60, 70, 80, 90 };
		Assert::IsTrue(expected == a);
	}

	TEST_METHOD(TestRemoveIf)
	{
		vector<int> a{ 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };

		// remove elements less than 35
		// does so by copying match elements to the front, overriding bad elements.
		auto newEnd = remove_if(begin(a), end(a), [](int &x) { return x < 35; });
		Assert::IsTrue(distance(a.begin(), newEnd) == 6);

		vector<int> aAfterRemove{ 40, 50, 60, 70, 80, 90, 60, 70, 80, 90 };
		Assert::IsTrue(aAfterRemove == a);

		// erase from the new end
		a.erase(newEnd, a.end());
		
		// a now has all elements > 35
		vector<int> expected{ 40, 50, 60, 70, 80, 90 };
		Assert::IsTrue(expected == a);
	}

	TEST_METHOD(TestRemoveIfShort)
	{
		vector<int> a{ 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };

		// remove elements less than 35
		// erase from the new end
		a.erase(remove_if(begin(a), end(a), [](int &x) { return x < 35; }), a.end());

		// a now has all elements > 35
		vector<int> expected{ 40, 50, 60, 70, 80, 90 };
		Assert::IsTrue(expected == a);
	}

	TEST_METHOD(TestRemoveCopy)
	{
		// copy all but a specific element to a new collection.
		vector<int> a{ 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
		vector<int> aBeforeRemove = a;
		vector<int> b;
		remove_copy(begin(a), end(a), back_inserter(b), 10);

		vector<int> expected = { 0, 20, 30, 40, 50, 60, 70, 80, 90 };
		Assert::IsTrue(expected == b);

		// a remains the same
		Assert::IsTrue(aBeforeRemove == a);
	}

	TEST_METHOD(TestRemoveCopyIf)
	{
		// copy all but elements matching a predicate
		vector<int> a{ 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
		vector<int> preA = a;

		vector<int> b;
		remove_copy_if(begin(a), end(a), back_inserter(b), [](int &x) { return x > 35; });

		vector<int> expected { 0, 10, 20, 30 };
		Assert::IsTrue(expected == b);

		Assert::IsTrue(a == preA);
	}

	/*
	Shuffle and sort
	*/
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
		std::vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		// transform inplace, quad-druple value
		transform(begin(vec), end(vec), begin(vec), [](int &x) { return x * 4; });

		// lower_bound assumes container is sorted by operator<
		auto lb = lower_bound(begin(vec), end(vec), 35);
		Assert::IsTrue(all_of(begin(vec), lb, [](int &x) { return x < 35; }));

		// upper_bound assumes container is sorted by operator<
		auto ub = upper_bound(begin(vec), end(vec), 35);
		Assert::IsTrue(all_of(ub, end(vec), [](int &x) { return x >= 35; }));
	}

	/*
	Tests the (pretty useless) binary search method.
	binary_search does not return an iterator but a boolean indicating if the value was found.
	*/
	TEST_METHOD(TestBinarySearch)
	{
		vector<int> a{ 0, 15, 17, 23, 32, 35, 46, 67, 85, 89, 90 };
		Assert::IsTrue(is_sorted(begin(a), end(a)));

		Assert::IsTrue(binary_search(begin(a), end(a), 23));
		Assert::IsFalse(binary_search(begin(a), end(a), 42));
	}

	/*
	Rotating collections
	*/
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

	/*
	Set operations
	*/
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

	TEST_METHOD(TestSetUnion)
	{
		// two sorted sets, with partially overlapping elements.
		vector<int> setA{ 0, 10, 20, 30, 40 };
		vector<int> setB{ 30, 40, 50, 60, 70, 80, 90 };

		// resulting vector holding result
		vector<int> setC;

		set_union(begin(setA), end(setA), begin(setB), end(setB), back_inserter(setC));

		vector<int> expected = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };

		Assert::IsTrue(expected == setC);
	}

	TEST_METHOD(TestSetSymmetricDifference)
	{
		vector<int> setA{ 0, 10, 20, 30, 40, 50 };
		vector<int> setB{ 40, 50, 60, 70, 80, 90 };

		vector<int> setC;
		set_symmetric_difference(begin(setA), end(setA), begin(setB), end(setB), back_inserter(setC));

		vector<int> expected = { 0, 10, 20, 30, 60, 70, 80, 90 };
		Assert::IsTrue(expected == setC);
	}

	/*
	Generating and filling
	*/
	TEST_METHOD(TestGenerate)
	{
		vector<int> a(10);
		int n = 0;
		generate(begin(a), end(a), [&]() { return n++; });

		vector<int> expected{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		Assert::IsTrue(expected == a);
	}

	TEST_METHOD(TestGenerateN)
	{
		vector<int> a;
		int n = 0;
		generate_n(back_inserter(a), 10, [&]() { return n++; });
		vector<int> expected{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		Assert::IsTrue(expected == a);
	}

	TEST_METHOD(TestIOTA)
	{
		vector<int> a(10);
		// iota fills the range with each increment of the start value (0)
		iota(begin(a), end(a), 0);

		vector<int> expected{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		Assert::IsTrue(expected == a);
	}

	TEST_METHOD(TestFill)
	{
		vector<int> a(10);
		fill(begin(a), end(a), 42);

		vector<int> expected{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
		Assert::IsTrue(expected == a);
	}

	/* 
	Partition 
	*/
	TEST_METHOD(TestPartition)
	{
		auto lessThan55 = [](int &x) { return x < 55; };
		vector<int> a{ 50, 40, 60, 30, 70, 20, 80, 10, 90, 0};
		auto middle = partition(begin(a), end(a), lessThan55);

		// partition makes no assumptions about ordering.
		// run assertions using all_of
		Assert::IsTrue(all_of(begin(a), middle, lessThan55));
		Assert::IsTrue(all_of(middle, end(a), [](int &x) { return x >= 55; }));
		Assert::IsTrue(is_partitioned(begin(a), end(a), lessThan55));
	}

	TEST_METHOD(TestStablePartition)
	{
		auto lessThan55 = [](int &x) { return x < 55; };
		vector<int> a{ 50, 40, 60, 30, 70, 20, 80, 10, 90, 0 };
		auto middle = stable_partition(begin(a), end(a), lessThan55);

		// stable partition keeps relative ordering ordering
		vector<int> lowerPart{ 50, 40, 30, 20, 10, 0 };
		vector<int> upperPart{ 60, 70, 80, 90 };
		Assert::IsTrue(equal(begin(lowerPart), end(lowerPart), begin(a)));
		Assert::IsTrue(equal(begin(upperPart), end(upperPart), middle));
	}

	TEST_METHOD(TestStablePartitionMovingSelectedElements)
	{
		class email
		{
		public:
			string from;
			string title;
			bool isSelected;
			bool operator==(const email& r) const
			{
				return from == r.from && 
						title == r.title && 
						isSelected == r.isSelected;
			}
		};

		vector<email> mailbox = 
		{
			email{ "philipp@software-architects.at", "change 10", false },
			email{ "philipp@software-architects.at", "lunch", false },
			email{ "rainer@software-architects.at", "RE: lunch", true },
			email{ "karin@software-architects.at", "RE: lunch", false },
			email{ "alex@software-architects.at", "RE: lunch", true },
			email{ "karin@software-architects.at", "RE: lunch", false },
		};

		stable_partition(begin(mailbox), end(mailbox), 
			[](email &m) { return m.isSelected; });

		vector<email> expected =
		{
			email{ "rainer@software-architects.at", "RE: lunch", true },
			email{ "alex@software-architects.at", "RE: lunch", true },
			email{ "philipp@software-architects.at", "change 10", false },
			email{ "philipp@software-architects.at", "lunch", false },
			email{ "karin@software-architects.at", "RE: lunch", false },
			email{ "karin@software-architects.at", "RE: lunch", false },
		};

		Assert::IsTrue(expected == mailbox);
	}

	/*
	accumulation
	*/
	TEST_METHOD(TestAccumulation)
	{
		vector<int> a(10);
		iota(begin(a), end(a), 0);

		auto sum = accumulate(begin(a), end(a), 0);

		Assert::AreEqual(0 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9, sum);
	}

	TEST_METHOD(TestAccumulationOfStrings)
	{
		vector<string> strings = { "This", "is", "a", "sentence" };
		auto combined = accumulate(begin(strings) + 1, end(strings), string(strings[0]), [](string acc, string v) { return acc + " " + v; });
		
		Assert::AreEqual(string("This is a sentence"), combined);
	}

	TEST_METHOD(TestInnerProduct)
	{
		vector<int> a = { 1, 2, 3, 4, 5 };
		vector<int> b = { 5, 4, 3, 2, 1 };
		auto innerProduct = inner_product(begin(a), end(a), begin(b), 0);

		Assert::AreEqual(1 * 5 + 2 * 4 + 3 * 3 + 4 * 2 + 5 * 1, innerProduct);
	}

	TEST_METHOD(TestMinMaxElement)
	{
		vector<int> a(10);
		iota(begin(a), end(a), -5);

		auto minmax = minmax_element(begin(a), end(a));

		Assert::AreEqual(-5, *minmax.first);
		Assert::AreEqual(4, *minmax.second);
	}

	TEST_METHOD(TestMinMax)
	{
		int a = 10;
		int b = 5;

		// incorrect: minmax returns references -> assigning
		// tie(a, b) = minmax(a, b);

		int c, d;
		tie(c, d) = minmax(a, b);

		Assert::AreEqual(5, c);
		Assert::AreEqual(10, d);
	}
};