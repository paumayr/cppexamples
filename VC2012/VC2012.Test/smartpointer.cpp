#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VC2012Test
{	
	class PrinterDriver
	{
	public:
		int handle;
		int *memoryResource;

		PrinterDriver()
			: handle(-1),
			memoryResource(nullptr)
		{
		}

		~PrinterDriver()
		{
			if (handle != -1)
			{
				// release kernel handle
				handle = -1;
			}

			delete[] memoryResource;
			memoryResource = nullptr;
		}

		void acquire()
		{
			handle = 10; // ... get kernel handle... bla bla
			memoryResource = new int[100]; // our memory resource, buffer.
		}

		void printPage() {}
		void writeText() {}
	};

	TEST_CLASS(SmartPointer)
	{
	public:
		TEST_METHOD(TestUniquePointer)
		{
			using namespace std;

			{
				auto driver = unique_ptr<PrinterDriver>();
				Assert::IsFalse(driver); // implicit conversion to bool
				driver = unique_ptr<PrinterDriver>(new PrinterDriver());
				Assert::IsTrue(driver);

				// cannot copy!
				// auto copyOfDriver = driver;

				// acts like a normal pointer
				driver->writeText();
				driver->printPage();

				// can set to null, but...
				driver = nullptr;

				// ... also automatically frees resources when running out of scope
			}
		}

		void passingSharedPointer(std::shared_ptr<PrinterDriver> printerDriver)
		{
			printerDriver->writeText();
		}

		TEST_METHOD(TestSharedPointer)
		{
			using namespace std;

			{
				auto driver = shared_ptr<PrinterDriver>();
				Assert::IsFalse(driver);

				driver.reset(new PrinterDriver());

				// can copy !
				auto copyOfDriver = driver;

				// acts like a normal pointer
				driver->writeText();
				copyOfDriver->printPage();

				// can easily be passed to function (like a normal pointer)
				passingSharedPointer(copyOfDriver);

				// can set pointer to nullptr
				// (does not release resource, because there is still a reference)
				driver = nullptr;

				// .. copyOfDriver will go out of scope
			}
		}

		TEST_METHOD(TestMakeShared)
		{
			using namespace std;
			{
				auto driver = shared_ptr<PrinterDriver>();
				Assert::IsFalse(driver);

				// more efficient version, only requires a single memory allocation.
				driver = make_shared<PrinterDriver>();

				// can copy !
				auto copyOfDriver = driver;

				// acts like a normal pointer
				driver->writeText();
				copyOfDriver->printPage();

				// can set pointer to nullptr 
				// (does not release resource, because there is still a reference)
				driver = nullptr;

				// .. copyOfDriver will go out of scope
			}
		}
	};
}