#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Demos
{

	TEST_CLASS(RValueReferences)
	{
		string getName()
		{
			string ret = "some name";
			return ret;
		}

		TEST_METHOD(TestReferences)
		{
			// valid, copy to result
			std::string resultCopy = getName();

			// "works", but is invalid, reference to destructed object
			std::string &resultReference = getName();

			// valid, hold R-value reference
			std::string && resultRRef = getName();

			auto var = resultRRef;
			bool result = var == "some name";
		}

		void print(int & value) { Logger::WriteMessage("Inside L-Value Reference print.\n"); }
		void print(int && value) { Logger::WriteMessage("Inside R-Value Reference print.\n"); }

		int getValue() { return 42; }

		TEST_METHOD(TestRValuePassingToFunction)
		{
			int value = 10;
			print(value);				// l-value

			print(int(30));				// r-value

			print(getValue());			// r-value

			int x;
			print((x = getValue()));	// l-value -> x is passed.

			{
				int y = 10;
				print(y);				// l-value, y is a named object and will be destructed _after_ the call finished
			}

			{
				int y = 10;
				print(std::move(y));	// r-value, std::move casts to an r-value
			}
		}

		class C { };

		C getC() { return C(); }

		void meth()
		{
			C a;
			C &b = a;
			// invalid, r-value-ref cannot be bound to l-value
			// C &&c = a;
			C &&c = getC();
		}
	};
}