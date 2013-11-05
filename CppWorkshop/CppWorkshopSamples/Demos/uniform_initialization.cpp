#include "stdafx.h"
#include "CppUnitTest.h"

#include <vector>
#include <initializer_list>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(Test)
{
	class MyClass
	{
	public:
		MyClass() { Logger::WriteMessage("MyClass Constructor"); };
	};

	TEST_METHOD(TestUniformInitialization)
	{
		// what does this do?
		MyClass a();

		// what does this do?
		MyClass b{};

		// initialization of arrays
		int arr[] { 1, 2, 3, 4, 5 };
	
		// initialization of structs
		struct PointStruct { int x, y; };
		PointStruct p { 10, 20 };

		class PointClass 
		{
			int x, y;
		public:
			PointClass(int x, int y) : x(x), y(y) {}
		};

		// C++11, now possible
		PointClass p1 { 30, 40 }; // call constructor!

		vector<PointClass> points 
		{
			{ 1, 2},
			{ 3, 4}
		};
	}

	template<typename T>
	class my_container
	{
	public:
		my_container(initializer_list<T> values)
		{
			// do something with values
			auto num = values.size();
			for (auto &x : values)
			{
				stringstream ss;
				ss << x << endl;
				Logger::WriteMessage(ss.str().c_str());
			}
		}
	};

	TEST_METHOD(TestInitializerList)
	{
		// use initializer_list constructor
		my_container<double> mc{ 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };

		// composes
		vector<my_container<double>> mc2
		{
			{ 1.0 },
			{ 2.0, 3.0 },
			{ 4.0, 5.0, 6.0 },
			{ 7.0, 8.0, 9.0, 10.0 },
		};

		// even further
		vector<vector<my_container<double>>> mc3
		{
			{
				{ 1.0 },
				{ 11.0},
			},
			{
				{ 2.0, 3.0 },
				{ 12.0, 13.0 },
			},
			{
				{ 4.0, 5.0, 6.0 },
				{ 14.0, 15.0, 16.0 },
			},
			{	
				{ 7.0, 8.0, 9.0, 10.0 },
				{ 17.0, 18.0, 19.0, 20.0 },
			}
		};
	}
};