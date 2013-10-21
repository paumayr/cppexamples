#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Demos
{		
	TEST_CLASS(UniquePointer)
	{
	public:
		
		class Person
		{
		public:
			Person(std::string firstName, std::string lastName)
				: _firstName(std::move(firstName)), _lastName(std::move(lastName))
			{
				// ... something to acquire resource
			}

			~Person()
			{
				// ... release resource
			}

			std::string _firstName;
			std::string _lastName;
		private:
			
		};



		TEST_METHOD(TestUniquePointer)
		{
			{
				auto philipp = std::unique_ptr<Person>(new Person("Philipp", "Aumayr"));

				// unique pointer cannot be copied:
				// auto copy_of = philipp;

				// transfer ownership from philipp to other.
				auto other = std::move(philipp);

				Assert::IsNull(philipp.get());
				Assert::IsNotNull(other.get());

				// destructor of object will be automatically called by destructor of "other"
			}

		}

	};
}