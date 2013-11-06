#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Demos
{
	TEST_CLASS(TestUnorderedMap)
	{
		TEST_METHOD(TestUnorderedMap1)
		{
			unordered_map<string, int> grades;
			grades["Philipp"] = 4;
			grades["Rainer"] = 3;

			unordered_map<string, int> grades2
			{
				{ "Philipp", 4 },
				{ "Rainer", 3 }
			};

			unordered_map<string, function<void()>> commands;
			commands["add"] = [](){ cout << "adding"; };
			commands["remove"] = []() { cout << "removing"; };


			unordered_map<string, function<void()>> commands2
			{
				{ "add", [](){ cout << "adding"; } },
				{ "remove", []() { cout << "removing"; } },
			};

		}
	};
}