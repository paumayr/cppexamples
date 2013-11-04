#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <functional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Demos
{
	TEST_CLASS(Lambdas)
	{
		static void my_function(int &variable)
		{
			variable++;
		}

		TEST_METHOD(TestFunctionCapture)
		{
			int myVariable = 0;

			// first guess: 
			function<void()> func = bind(my_function, myVariable);
			
			// Correct: function<void()> func = bind(my_function, ref(myVariable));
			func(); 

			Assert::AreEqual(myVariable, 0);
		}
	};
}