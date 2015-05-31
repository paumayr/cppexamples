#include "stdafx.h"
#include "CppUnitTest.h"

#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SampleTests
{
	ostream & operator<<(ostream &os, map<string, int> m)
	{
		// map supports iteration
		os << "m = ";
		for_each(begin(m), end(m),
			[&](map<string, int>::value_type x) { os << "(" << x.first << ", " << x.second << "), "; });

		os << endl;
		return os;
	}

	TEST_CLASS(Map)
	{
	public:
		
		TEST_METHOD(TestMap)
		{
			map<string, int> shoppinglist;

			// index operations
			shoppinglist["apples"] = 2;
			shoppinglist["bananas"] = 10;

			// at can only be used on existing elements
			shoppinglist.at("bananas") = 30;
			cout << shoppinglist;

			// elements can be removed
			shoppinglist.erase("apples");
			cout << shoppinglist;

			// can be cleared
			shoppinglist.clear();
			cout << shoppinglist;

			// maps are always sorted, no matter in which order they are inserted
			map<string, int> alpha;
			alpha["a"] = 0;
			alpha["b"] = 1;
			alpha["e"] = 4;
			alpha["f"] = 5;
			alpha["c"] = 2;
			alpha["d"] = 3;
			cout << alpha;

			// remove erase pattern can be used on ranges
			// e.g. delete elements from c (including) to e (excluding), remaining map contains a, b, e, f
			alpha.erase(alpha.find("c"), alpha.find("e"));
			cout << alpha;
		}

	};
}