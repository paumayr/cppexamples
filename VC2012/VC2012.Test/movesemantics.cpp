#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VC2012Test
{	
	using namespace std;

	template <class T>
	class MyContainer
	{
		T *elements;
		size_t count;
	public:
		// classic constructor
		MyContainer(size_t count) : elements(new T[count]),	count(count)
		{}

		~MyContainer()	{ delete[] elements; }

		// copy constructor
		MyContainer(const MyContainer& other) : elements(new T[other.count]), count(other.count) {
			std::copy(other.elements, other.elements + other.count, elements);
		}

		// copy assignment operator
		const MyContainer& operator=(const MyContainer &other)
		{
			if (this != &other)
			{
				delete[] elements;
				count = other.count;
				elements = new T[other.count];

				for(size_t i = 0; i < count; i++)
				{
					elements[i] = other.elements[i];
				}
			}

			return *this;
		}

		// move constructor
		MyContainer(MyContainer && source) : count(source.count), elements(source.elements)
		{
			source.count = 0;
			source.elements = nullptr;
		}

		// move assignment operator
		const MyContainer& operator=(MyContainer &&other)
		{
			delete[] elements;
			elements = other.elements;
			count = other.count;

			other.elements = nullptr;
			other.count = 0;

			return *this;
		}

		int & operator[](size_t index)
		{
			return elements[index];
		}
	};

	void CreateNumbers(std::vector<int> &target)
	{
		for (int i = 0; i < 100; i++)
		{
			target.push_back(i);
		}
	}

	TEST_CLASS(MoveSemantics)
	{
	public:

		MyContainer<int> CreateContainer()
		{
			auto m = MyContainer<int>(100);
			for (int i = 0; i < 100; i++)
			{
				m[i] = i;
			}

			return m;
		}

		TEST_METHOD(TestMoveConstructor)
		{
			MyContainer<int> container1(100);
			
			// move constructor
			auto container2 = CreateContainer();

			{
				MyContainer<int> container3(200);

				// explicit move assignment
				container2 = std::move(container3);

				// copy constructor
				container2 = container3;

				// implicit move assignment 
				container2 = MyContainer<int>(1000);

				// implicit move assignment
				container2 = CreateContainer();
			}

		}
	};
}