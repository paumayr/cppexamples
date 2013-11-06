#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <vector>
#include <future>
#include <tuple>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

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
		MyNoisyClass &operator=(MyNoisyClass &other) { Logger::WriteMessage("copy assignment operator\n"); return *this; }
		
		// RValue assignment operator
		MyNoisyClass &operator=(MyNoisyClass &&other) { Logger::WriteMessage("RValue assignment operator\n"); return *this; }
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

		TEST_METHOD(TestMoveVector)
		{
			vector<int> x{ 10, 20, 30, 40, 50, 50 };

			std::move(x);

			//auto y = std::move(x);
		}

		TEST_METHOD(TestLambdaNoisyClass)
		{
			auto f1 = async([]() { return std::move(MyNoisyClass()); });
			auto result = f1.get();
		}


		template<typename ...T>
		void func1(T &&... arg)
		{
			auto t = make_tuple(arg...);
		}

		template<typename ...T>
		void func2(T &&... arg)
		{
			func1(arg...);
		}

		TEST_METHOD(TestForwardVsMove)
		{
			func2(10, 20, 30);
			int x = 30;
			func2(10, x);
		}
	};
}