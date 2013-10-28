#include "stdafx.h"
#include "CppUnitTest.h"
#include <memory>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Demos
{
	TEST_CLASS(MoveSemantics)
	{
		class NoisyClass
		{
		public:
			std::string name;

			NoisyClass(std::string _name)
				: name(_name)
			{
				Logger::WriteMessage(("Constructor for " + name).c_str());
			}

			~NoisyClass() { Logger::WriteMessage(("Destructor for " + name).c_str()); }

			// copy constructor
			NoisyClass(NoisyClass &other)
			{
				Logger::WriteMessage(("Copy constructor for (other.name = " + name + ")").c_str());
				this->name = "Copy of " + other.name;
			}
		};

		class MoveableNoisyClass
		{
		public:
			std::string name;
			MoveableNoisyClass(std::string _name)
			{
				Logger::WriteMessage(("Constructor for " + name).c_str());
			}

			~MoveableNoisyClass() { Logger::WriteMessage(("Destructor for " + name).c_str()); }

			// copy constructor
			MoveableNoisyClass(MoveableNoisyClass &other)
			{
				Logger::WriteMessage(("Copy constructor for (other.name = " + name + ")").c_str());
				this->name = "Copy of " + other.name;
			}

			// move constructor
			MoveableNoisyClass(MoveableNoisyClass &&other)
				: name(std::move(other.name))
			{
				Logger::WriteMessage(("Move constructor for (other.name = " + name + ")").c_str());
			}
		};


		NoisyClass CreateNoisyClass()
		{
			NoisyClass y("a");
			return y;
		}

		TEST_METHOD(TestCopyConstructor)
		{
			auto y = CreateNoisyClass();
			Logger::WriteMessage(y.name.c_str());
		}

		void SomeOperationUsingMove(MoveableNoisyClass y)
		{
			Logger::WriteMessage(("Got " + y.name).c_str());
		}

		TEST_METHOD(TestMoveConstructor)
		{
			SomeOperationUsingMove(MoveableNoisyClass("a"));
		}

		void LogAddress(void *address)
		{
			std::stringstream ss;
			ss << "Address: ";
			ss << address;
			ss << std::endl;

			auto s = ss.str();
			Logger::WriteMessage(s.c_str());
		}

		std::vector<int> FillVector()
		{
			std::vector<int> b = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

			LogAddress(&b[0]);
			return b;
		}

		TEST_METHOD(TestMoveSemantics)
		{
			// use watch window to inspect
			auto a = FillVector();
			LogAddress(&a[0]);
		}
	};
}