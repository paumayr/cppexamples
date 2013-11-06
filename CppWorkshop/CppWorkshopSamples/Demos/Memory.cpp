#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Demos
{
	TEST_CLASS(MemoryManagement)
	{
		class SomeResource
		{
			int *resource;
		public:
			SomeResource() : resource(new int[1024 * 1024]) {}
			~SomeResource() {
				if (resource != nullptr)
				{
					delete[] resource;
				}
			}

			SomeResource(SomeResource &other)
			{
			}

			void operator=(SomeResource &other)
			{
				if (this != &other)
				{
					delete[] resource;
					resource = other.resource;
					other.resource = nullptr;
				}
			}
		};

		void func(SomeResource p) {

		}

		TEST_METHOD(SomeResourceDoubleDelete)
		{
			SomeResource x1;
			SomeResource x2;
			x2 = x1;
			x2 = x2;
			// This causes trouble: func(x2);
		}
	};

}