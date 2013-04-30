#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VC2012Test
{	
	using namespace std;

	TEST_CLASS(CodeAnalysis)
	{
	public:
		TEST_METHOD(ArrayOfByOne)
		{
			char arr[10];
			int asdf;
			int jklm;
			// arr[10] = '\0';
			arr[9] = '\0';

			if (sizeof(arr) == 10)
			{
				asdf = 5;
			}

			jklm = asdf;
		}

		TEST_METHOD(RedundantCodeCheck)
		{
			int x = 5;
			int y = 3;

			if (x != 0 && x != 0)
			{
				printf("asdf");
			}

		}
	};
}