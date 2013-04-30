#include "stdafx.h"
#include "CppUnitTest.h"
#include <initializer_list>
#include <typeinfo>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VC2012Test
{	
	using namespace std;

	class mycontainer
	{
		float *_data;
		size_t _size;
	public:

		mycontainer(std::initializer_list<float> v)
			: _data(new float[v.size()]),
			_size(v.size())
		{
			std::copy(v.begin(), v.end(), _data);
		}

		
		~mycontainer()
		{
			delete[] _data;
			_size = 0;
		}

		float operator[](size_t index) { return _data[index]; }
		size_t size() const { return _size; }
	private:
		mycontainer(mycontainer& other) {};
		mycontainer& operator=(mycontainer &other) {};
	};


	TEST_CLASS(InitializerLists)
	{
	public:
		TEST_METHOD(TestInitializerList)
		{
			auto y = {1, 2, 3, 4};
			auto name = typeid(y).name();

			mycontainer x = { 1.0f, 2.0f, 3.0f, 4.0f };

			Assert::IsTrue(4 == x.size());
			Assert::AreEqual(1.0f, x[0]);
			Assert::AreEqual(2.0f, x[1]);
			Assert::AreEqual(3.0f, x[2]);
			Assert::AreEqual(4.0f, x[3]);
		}
	};
}