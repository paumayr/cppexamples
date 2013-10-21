#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

BEGIN_TEST_MODULE_ATTRIBUTE()
	TEST_MODULE_ATTRIBUTE(L"MyAttribute", L"asdf")
END_TEST_MODULE_ATTRIBUTE()

int LoggerReportHook(int reportType, char *message, int *returnValue)
{
	Logger::WriteMessage(message);
	return 1;
}

TEST_MODULE_INITIALIZE(TestModuleInitialize)
{
	_CrtSetReportHook(LoggerReportHook);
}

TEST_MODULE_CLEANUP(TestModuleCleanup)
{}


namespace SampleTestProject
{		
	TEST_CLASS(UnitTest1)
	{

	public:
		_CrtMemState beforeTest;
		_CrtMemState afterTest;

		TEST_CLASS_INITIALIZE(TestClassInitialize)
		{}

		TEST_CLASS_CLEANUP(TestClassCleanup)
		{}
	
		TEST_METHOD_INITIALIZE(TestMethodInitialize)
		{
			Logger::WriteMessage(L"Recording memory check point before test.\n");
			_CrtMemCheckpoint(&beforeTest);
		}

		TEST_METHOD_CLEANUP(TestMethodCleanup)
		{
			Logger::WriteMessage(L"Recording memory check point after test.\n");
			_CrtMemCheckpoint(&afterTest);
			_CrtMemState difference;

			Logger::WriteMessage(L"Calcluating difference between tests.\n");
			if (_CrtMemDifference(&difference, &beforeTest, &afterTest))
			{
				_CrtMemDumpStatistics(&difference);
				Assert::Fail(L"memory leak found");
			}
		}

		TEST_METHOD(TestMethod1)
		{
			Logger::WriteMessage(L"Executing simple test");
			int answer = 35 + 7;
			Assert::AreEqual(42, answer);
		}

		TEST_METHOD(TestMethodLeakingMemory)
		{
			{
				int *myleak = new int[10000];
				// Uncomment this to trigger memory leak
				delete[] myleak;
			}

			_CrtMemDumpAllObjectsSince(NULL);
		}
	};
}







