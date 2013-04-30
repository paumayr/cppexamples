#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VC2012Test
{	
	using namespace std;

	TEST_CLASS(HashTables)
	{
	public:
		TEST_METHOD(TestUnorderedMap)
		{
			unordered_map<string, string> phonebook;
			phonebook["Philipp Aumayr"] = "+43664....";
			phonebook["Rainer Stropek"] = "+43699....";

			auto& phil = phonebook["Philipp Aumayr"];

			Assert::AreEqual(string("+43664...."), phil);
			
			// default constructs
			auto& unknown = phonebook["Raphael Schwarz"];
			
			unknown = "+43699...";

			auto& raphael = phonebook["Raphael Schwarz"];
			Assert::AreEqual(string("+43699..."), raphael);

			// tests contains
			Assert::IsTrue(phonebook.end() == phonebook.find(string("Unknown")));
			Assert::IsTrue(0 == phonebook.count(string("Unknown")));

			// replaces existing
			phonebook["Raphael Schwarz"] = "+43699123456";
		}

		TEST_METHOD(TestUnorderedMultimap)
		{
			unordered_multimap<string, string> phonebook;

			phonebook.insert(std::make_pair("Philipp Aumayr", "+43664....1"));
			phonebook.insert(std::make_pair("Philipp Aumayr", "+43664....2"));

			phonebook.insert(std::make_pair("Raphael Schwarz", "+43699....1"));
			phonebook.insert(std::make_pair("Raphael Schwarz", "+43699....2"));
			phonebook.insert(std::make_pair("Raphael Schwarz", "+43699....3"));

			auto philnumbers = phonebook.equal_range("Philipp Aumayr");
			auto raphaelnumbers = phonebook.equal_range("Raphael Schwarz");

			Assert::AreEqual(2, std::distance(philnumbers.first, philnumbers.second));
			Assert::AreEqual(3, std::distance(raphaelnumbers.first, raphaelnumbers.second));

			Assert::AreEqual(string("+43664....1"), (*philnumbers.first).second);
			Assert::AreEqual(string("+43664....2"), (*std::next(philnumbers.first)).second);

			Assert::AreEqual(string("+43699....1"), (*raphaelnumbers.first).second);
			Assert::AreEqual(string("+43699....2"), (*std::next(raphaelnumbers.first)).second);
			Assert::AreEqual(string("+43699....3"), (*std::next(std::next(raphaelnumbers.first))).second);
		}

		TEST_METHOD(TestUnorderedSet)
		{
			unordered_set<string> speaker;

			speaker.insert("Philipp Aumayr");
			speaker.insert("Raphael Schwarz");
			speaker.insert("Rainer Stropek");

			Assert::IsTrue(speaker.count("Philipp Aumayr") == 1);
			Assert::IsTrue(speaker.count("Herb Sutter") == 0); // unfortunately

			Assert::AreEqual(3u, speaker.size());

			// inserting already added element does not re-add
			speaker.insert("Rainer Stropek");

			Assert::AreEqual(3u, speaker.size());

			// support for range based for loop.
			int count = 0;
			for (auto x : speaker)
			{
				count++;
			}
			
			Assert::AreEqual(3, count);
		}

		TEST_METHOD(TestUnorderedMultiset)
		{
			unordered_multiset<string> speaker;

			speaker.insert("Philipp Aumayr");
			speaker.insert("Raphael Schwarz");
			speaker.insert("Rainer Stropek");

			Assert::IsTrue(speaker.count("Philipp Aumayr") == 1);
			Assert::IsTrue(speaker.count("Herb Sutter") == 0); // unfortunately

			Assert::AreEqual(3u, speaker.size());

			// inserting already added element does re-add
			speaker.insert("Rainer Stropek");

			Assert::AreEqual(4u, speaker.size());

			// support for range based for loop.
			int count = 0;
			for (auto x : speaker)
			{
				count++;
			}
			
			Assert::AreEqual(4, count);
		}
	};
}