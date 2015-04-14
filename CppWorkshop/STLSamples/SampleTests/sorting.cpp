#include "stdafx.h"
#include "CppUnitTest.h"

#include <algorithm>
#include <vector>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SampleTests
{
	std::ostream& operator<<(std::ostream &stream, std::vector<int> &v)
	{
		for (auto x : v) stream << x << ", ";
		return stream;
	}

	TEST_CLASS(Sorting)
	{
	public:
		
		TEST_METHOD(TestSorting)
		{
			using namespace std;

			vector<int> v;
			for (int i = 0; i < 10; i++)
			{
				v.push_back(i);
			}

			// shuffle the elements.
			random_shuffle(begin(v), end(v));
			cout << "randomized: " << v << endl;

			// sort (default ascending)
			sort(begin(v), end(v));
			cout << "sorted, ascending: " << v << endl;

			// sorted descending
			sort(begin(v), end(v), [](int lh, int rh) { return lh > rh; });
			cout << "sorted, descending: " << v << endl;
		}

	};
}