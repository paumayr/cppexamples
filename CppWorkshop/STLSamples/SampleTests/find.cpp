#include "stdafx.h"
#include "CppUnitTest.h"

#include <vector>
#include <algorithm>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SampleTests
{
	TEST_CLASS(Find)
	{
	public:
		
		TEST_METHOD(TestFind)
		{
			using namespace std;
			vector<int> v{ 0, 1, 2, 3, 4, 5, 5, 5, 6, 7 };

			// find the first occurence
			auto posFirst5 = find(begin(v), end(v), 5);
			Assert::AreEqual(&(*posFirst5), &v[5]);

			// find the last occurence
			auto posLast5 = find(rbegin(v), rend(v), 5);
			Assert::AreEqual(&(*posLast5), &v[7]);

			// find any element of another collection
			vector<int> tofind{ 3, 6, 7 };
			auto firstPattern = find_first_of(begin(v), end(v),
							begin(tofind), end(tofind));

			Assert::IsTrue(firstPattern == (v.begin() + 3));

			// find first element matching predicate
			auto pred = [](int x) { return x > 3; };
			auto firstMatch = find_if(begin(v), end(v), pred);
			Assert::IsTrue(*firstMatch == 4);

			// find next element matching predicate
			auto secondMatch = find_if(firstMatch + 1, end(v), pred);
			Assert::IsTrue(*secondMatch == 5);

			// find no match
			auto nomatch = find_if(begin(v), end(v), [](int x) { return x > 20; });
			Assert::IsTrue(nomatch == end(v));
		}

		TEST_METHOD(TestSearch)
		{
			using namespace std;
			vector<int> v{ 0, 1, 4, 5, 2, 3, 4, 5, 6, 7 };

			vector<int> pattern{ 3, 4, 5 };
			auto sequence = search(begin(v), end(v), begin(pattern), end(pattern));
			Assert::IsTrue(sequence == (begin(v) + 5));
		}

	};
}