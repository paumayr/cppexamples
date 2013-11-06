#include "stdafx.h"
#include "CppUnitTest.h"
#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_generators.hpp"


#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Demo_Boost
{
	TEST_CLASS(Guid)
	{
	public:

		TEST_METHOD(TestGuid)
		{
			using namespace boost::uuids;
			
			uuid g1 = random_generator()();
			uuid g2 = random_generator()();

			Assert::IsFalse(g1 == g2);

			uuid empty = boost::uuids::nil_uuid();
			Assert::IsTrue(empty == string_generator()("{00000000-0000-0000-0000-000000000000}"));
		}
	};
}