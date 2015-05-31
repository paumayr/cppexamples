
#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

#define MYMAX(a, b) (a < b ? b : a)

#ifdef LINUX

#endif

#if LINUX == 10
#define ASDF
#else

#define JKLM

#endif



namespace Demos
{
	TEST_CLASS(VirtualDestructor)
	{
		class Base
		{
		public:
			~Base() // Non-virtual Destructor, bad practice!
			{
			}
		};

		class Derived : public Base
		{
		public:
			~Derived()
			{
			}
		};

		TEST_METHOD(TestVirtualDestructor)
		{
			{
				std::shared_ptr<Base> base = std::shared_ptr<Base>(new Derived());
			}
		}

		int firstFunc()
		{
			return 10;
		}

		int secondFunc()
		{
			return 20;
		}

		TEST_METHOD(TestMacros)
		{
			auto x = MYMAX(firstFunc(), secondFunc());
		}
	};
}