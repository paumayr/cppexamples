#include "stdafx.h"
#include "CppUnitTest.h"

#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SampleTests
{
	ostream& operator<<(ostream &os, list<int> l)
	{
		os << "l =";
		for_each(begin(l), end(l),
			[&](int x) { os << " " << x; });

		os << endl;
		return os;
	}

	TEST_CLASS(Lists)
	{
	public:

		void TestLists()
		{
			list<int> l;

			// lists allow insertion at begin and at end
			l.push_front(5);
			l.push_back(10);

			cout << l;

			// lists are not adjacent elements, like vectors:
			int *firstelem = &(*l.begin());
			int *secondelem = &(*(l.begin()++));

			if (firstelem + 1 == secondelem)
			{
				std::cout << "first element is next to second element in memory" << endl;
			}
			else
			{
				std::cout << "first element NOT adjacent to second element in list" << endl;
			}
		}
	};
}