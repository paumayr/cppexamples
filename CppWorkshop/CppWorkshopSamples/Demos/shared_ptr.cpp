#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Demos
{
	TEST_CLASS(SharedPointer)
	{
		TEST_METHOD(TestSharedPointer)
		{
			using namespace std;

			auto a = shared_ptr<int>(new int(100));
			Assert::AreEqual(100, *a);

			Assert::AreEqual(1l, a.use_count());

			{
				auto b = a;
				Assert::AreEqual(2l, a.use_count());
				Assert::AreEqual(2l, b.use_count());
				Assert::AreEqual(*a, *b);
			}

			Assert::AreEqual(1l, a.use_count());
		}
	};
}