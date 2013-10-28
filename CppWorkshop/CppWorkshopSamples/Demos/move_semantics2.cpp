#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Demos
{
	class MyNoisyClass
	{
	public:
		MyNoisyClass() { Logger::WriteMessage("Constructor\n"); }
		~MyNoisyClass() { Logger::WriteMessage("Destructor\n"); }

		// copy constructor
		MyNoisyClass(MyNoisyClass &other) { Logger::WriteMessage("Copy constructor\n"); }
		
		// RValue constructor
		MyNoisyClass(MyNoisyClass &&other) { Logger::WriteMessage("RValue constructor\n"); }

		// copy assignment operator
		MyNoisyClass &operator=(MyNoisyClass &other) { Logger::WriteMessage("copy assignment operator\n"); }
		
		// RValue assignment operator
		MyNoisyClass &operator=(MyNoisyClass &&other) { Logger::WriteMessage("RValue assignment operator\n"); }
	};

	TEST_CLASS(MoveSemantics2)
	{
		TEST_METHOD(TestMoveSemantics)
		{
			MyNoisyClass a;
		}

		void passParameter(MyNoisyClass x)
		{
			Logger::WriteMessage("In passParameters\n");
		}

		TEST_METHOD(TestParameterPassingLocal)
		{
			// calls copy constructor, because x is not a R value reference
			MyNoisyClass x;
			passParameter(x);
		}

		TEST_METHOD(TestParameterPassingTemporary)
		{
			passParameter(MyNoisyClass());
		}

		TEST_METHOD(TestParameterPassingMove)
		{
			// do NOT do this in production.
			// used to prevent copy elision. It's safe, but slower.
			passParameter(std::move(MyNoisyClass()));
		}

		static void OldReadDataFromFile(const std::string& filename, /* OUT */ std::vector<float> &data)
		{
			///.... fill data
		}

		static std::vector<float> ReadDataFromFile(const std::string& filename)
		{
			std::vector<float> result;
			// ... fill data 
			return result;
		}

		void LoadScenario()
		{
			std::vector<float> data;
			OldReadDataFromFile("filename.txt", data);
			// ... use data ...

			// Call site
			const auto newData = ReadDataFromFile("filename.txt");
		}
	};
}