#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SampleTests
{
	TEST_CLASS(Vector)
	{
	public:
		void printvector(std::vector<int> v)
		{
			for (size_t i = 0; i < v.size(); i++)
			{
				std::cout << v[i] << ", ";
			}

			std::cout << std::endl;
		}
		
		TEST_METHOD(TestVector)
		{
			vector<int> v;

			// add elements to the back
			v.push_back(10);
			v.push_back(20);

			// v now contains 2 ints, 10 and 20
			printvector(v);

			// elements can be popped from the back
			v.pop_back();

			// v now contains 1 int, 1
			printvector(v);

			// vector can be constructed with n elements of the same value ( vector(count, value) )
			vector<int> v2(10, 42);

			// elements can be inserted at any position from another pair of iterators
			v.insert(v.end(), v2.begin(), v2.end());

			// v now contains 11 elements, 1, and 10x 42
			printvector(v);

			// vectors can be cleared, keeps the memory buffer...
			v.clear();

			// v is now empty
			printvector(v);
			cout << "v.empty() = " << v.empty() << std::endl;

			// the capacity of the vector remains
			cout << "v.capacity() = " << v.capacity() << endl;

			// until shrink_to_fit is called
			v.shrink_to_fit();

			cout << "v.capacity() = " << v.capacity() << endl;

			// refill vector
			v.push_back(10);
			v.insert(v.end(), begin(v2), end(v2));

			// elements can be removed using the remove-erase paradigm
			v.erase(std::remove(begin(v), end(v), 1), end(v));

			// v now contains 10 x 42
			printvector(v);

			int *firstelem = &v[0];
			int *secondelem = &v[1];

			if (firstelem + 1 == secondelem)
			{
				std::cout << "first element is next to second element in vector" << endl;
			}
			else
			{
				std::cout << "first element NOT adjacent to second element in vector" << endl;
			}
		}

	};
}